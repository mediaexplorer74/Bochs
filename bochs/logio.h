/////////////////////////////////////////////////////////////////////////
// $Id: logio.h 14100 2021-01-30 19:40:18Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#include "bxthread.h"
#include "../iodev/display/voodoo_data.h"
#include <winnt.h>
#include "../gui/siminterface.h"
#ifndef BX_LOGIO_H
#define BX_LOGIO_H

// Log level defines
typedef enum {
  LOGLEV_DEBUG = 0,
  LOGLEV_INFO,
  LOGLEV_ERROR,
  LOGLEV_PANIC,
  N_LOGLEV
} bx_log_levels;

// Log action defines
typedef enum {
  ACT_IGNORE = 0,
  ACT_REPORT,
  ACT_WARN,
  ACT_ASK,
  ACT_FATAL,
  N_ACT
} bx_log_actions;

typedef class BOCHSAPI logfunctions
{
  char *name;
  char *prefix;
  int onoff[N_LOGLEV];
  class iofunctions *logio;
  // default log actions for all devices, declared and initialized
  // in logio.cc.
  BOCHSAPI_CYGONLY static int default_onoff[N_LOGLEV];
public:
  logfunctions(void);
  logfunctions(class iofunctions *);
  virtual ~logfunctions(void);

  void info(const char *fmt, ...)   BX_CPP_AttrPrintf(2, 3);
  void error(const char *fmt, ...)  BX_CPP_AttrPrintf(2, 3);
  void panic(const char *fmt, ...)  BX_CPP_AttrPrintf(2, 3);
  void ldebug(const char *fmt, ...) BX_CPP_AttrPrintf(2, 3);
  void fatal1(const char *fmt, ...) BX_CPP_AttrPrintf(2, 3);
  void fatal(int level, const char *prefix, const char *fmt, va_list ap, int exit_status);
  void warn(int level, const char *prefix, const char *fmt, va_list ap);
  void ask(int level, const char *prefix, const char *fmt, va_list ap);
  void put(const char *p);
  void put(const char *n, const char *p);
  void setio(class iofunctions *);
  void setonoff(int loglev, int value) {
    assert (loglev >= 0 && loglev < N_LOGLEV);
    onoff[loglev] = value;
  }
  const char *get_name() const { return name; }
  const char *getprefix() const { return prefix; }
  int getonoff(int level) const {
    assert (level>=0 && level<N_LOGLEV);
    return onoff[level];
  }
  static void set_default_action(int loglev, int action) {
    assert (loglev >= 0 && loglev < N_LOGLEV);
    assert (action >= 0 && action < N_ACT);
    default_onoff[loglev] = action;
  }
  static int get_default_action(int loglev) {
    assert (loglev >= 0 && loglev < N_LOGLEV);
    return default_onoff[loglev];
  }
} logfunc_t;

#define BX_LOGPREFIX_LEN 20

class BOCHSAPI iofunctions 
{
  int magic;
  char logprefix[BX_LOGPREFIX_LEN + 1];
  FILE *logfd;
  class logfunctions *log;
  void init(void);
  void flush(void);

// Log Class types
public:
  iofunctions(void);
  iofunctions(FILE *);
  iofunctions(int);
  iofunctions(const char *);
 ~iofunctions(void);

 void out(int level, const char* pre, const char* fmt, va_list ap)
 {
     char c = ' ', * s;
     char tmpstr[80], msgpfx[80], msg[1024];

     assert(magic == MAGIC_LOGNUM);
     assert(this != NULL);
     assert(logfd != NULL);

     BX_LOCK(logio_mutex);

     switch (level) {
     case LOGLEV_INFO: c = 'i'; break;
     case LOGLEV_PANIC: c = 'p'; break;
     case LOGLEV_ERROR: c = 'e'; break;
     case LOGLEV_DEBUG: c = 'd'; break;
     default: break;
     }

     s = logprefix;
     msgpfx[0] = 0;
     while (*s) {
         switch (*s) {
         case '%':
             if (*(s + 1)) s++;
             else break;
             switch (*s) 
             {
             case 'd':
#pragma warning(suppress : 4996)
                 sprintf(tmpstr, "%s", "");// prefix == NULL ? "" : prefix);
                 break;
             case 't':
#pragma warning(suppress : 4996)
                 sprintf(tmpstr, FMT_TICK, "");// bx_pc_system.time_ticks());
                 break;
             case 'i':
#if BX_SUPPORT_SMP == 0
#pragma warning(suppress : 4996)
                 sprintf(tmpstr, "%08x", "");// BX_CPU(0)->get_eip());
#endif
                 break;
             case 'e':
#pragma warning(suppress : 4996)
                 sprintf(tmpstr, "%c", c);
                 break;
             case '%':
#pragma warning(suppress : 4996)
                 sprintf(tmpstr, "%%");
                 break;
             default:
#pragma warning(suppress : 4996)
                 sprintf(tmpstr, "%%%c", *s);
             }
             break;
         default:
#pragma warning(suppress : 4996)
             sprintf(tmpstr, "%c", *s);
         }

#pragma warning(suppress : 4996)
         strcat(msgpfx, tmpstr);

         s++;
     }

     fprintf(logfd, "%s ", msgpfx);

     if (level == LOGLEV_PANIC)
     {
         fprintf(logfd, ">>PANIC<< ");
     }

#pragma warning(suppress : 4996)
     vsnprintf(msg, sizeof(msg), fmt, ap);

     fprintf(logfd, "%s\n", msg);

     fflush(logfd);
     if (SIM->has_log_viewer())
     {
         SIM->log_msg(msgpfx, level, msg);
     }

     BX_UNLOCK(logio_mutex);
 }

  void init_log(const char *fn);
  void init_log(int fd);
  void init_log(FILE *fs);
  void exit_log();
  void set_log_prefix(const char *prefix);
  int get_n_logfns() const { return n_logfn; }
  logfunc_t *get_logfn(int index) { return logfn_list[index]; }
  void add_logfn(logfunc_t *fn);
  void remove_logfn(logfunc_t *fn);
  void set_log_action(int loglevel, int action);
  const char *getlevel(int i) const;
  const char *getaction(int i) const;
  int isaction(const char *val) const;

protected:
  int n_logfn;
#define MAX_LOGFNS 512
  logfunc_t *logfn_list[MAX_LOGFNS];
  const char *logfn;
};//iofunctions class


typedef class iofunctions iofunc_t;

#define SAFE_GET_IOFUNC() \
  ((io==NULL)? (io=new iofunc_t("/dev/stderr")) : io)

#define SAFE_GET_GENLOG() \
  ((genlog==NULL)? (genlog=new logfunc_t(SAFE_GET_IOFUNC())) : genlog)


#if BX_NO_LOGGING

#define BX_INFO(x)
#define BX_DEBUG(x)
#define BX_ERROR(x)
#define BX_PANIC(x) (LOG_THIS panic) x
#define BX_FATAL(x) (LOG_THIS fatal1) x

#define BX_ASSERT(x)

#else

#define BX_INFO(x)  (LOG_THIS info) x
#define BX_DEBUG(x) (LOG_THIS ldebug) x
#define BX_ERROR(x) (LOG_THIS error) x
#define BX_PANIC(x) (LOG_THIS panic) x
#define BX_FATAL(x) (LOG_THIS fatal1) x

#if BX_ASSERT_ENABLE
  #define BX_ASSERT(x) do {if (!(x)) BX_PANIC(("failed assertion \"%s\" at %s:%d\n", #x, __FILE__, __LINE__));} while (0)
#else
  #define BX_ASSERT(x)
#endif

#endif



BOCHSAPI extern iofunc_t *io;
BOCHSAPI extern logfunc_t *genlog;

#define BX_NULL_PREFIX  "[      ]"

#endif
