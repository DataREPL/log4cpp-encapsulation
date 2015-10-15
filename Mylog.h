#ifndef _MYLOG_H
#define _MYLOG_H

#include <log4cpp/Category.hh>

enum Priority
{
	ERROR,
	WARN,
	INFO,
	DEBUG
};

class Mylog
{
public:
	static Mylog & getInstance();

	static void destroy();

	void setPriority(Priority priority);
	void error(const char *msg);
	void warn(const char *msg);
	void debug(const char *msg);
	void info(const char *mgs);

private:
	Mylog();

private:
	static Mylog *plog_;
	log4cpp::Category &catRef_;
};

inline std::string int2string(int line)
{
	std::ostringstream os;
	os << line;
	return os.str();
}

#define postfix(msg)  std::string(msg).append(" ##")\
	.append(__FILE__).append(":").append(__func__)\
	.append(":").append(int2string(__LINE__))\
	.append("##").c_str()

#ifdef LOG4CPP
Mylog &log = Mylog::getInstance();
#else
extern Mylog &log;
#endif

#define LOG_ERROR(msg) log.error(postfix(msg)) 
#define LOG_WARN(msg)  log.warn(postfix(msg))
#define LOG_INFO(msg)  log.info(postfix(msg))
#define LOG_DEBUG(msg) log.debug(postfix(msg))


#endif
