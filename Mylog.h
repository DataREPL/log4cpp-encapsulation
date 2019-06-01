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

    log4cpp::Category *getLogger();

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

#define prefix(fmt)  std::string(__func__).append(": ").append(int2string(__LINE__))\
	.append(": ").append(fmt).c_str()

#ifdef LOG4CPP
Mylog &log = Mylog::getInstance();
#else
extern Mylog &log;
#endif

#define LOG_ERROR(fmt,...) log.getLogger()->error(prefix(fmt), #__VA_ARGS__)
#define LOG_WARN(fmt,...)  log.getLogger()->warn(prefix(fmt), #__VA_ARGS__)
#define LOG_INFO(fmt,...)  log.getLogger()->info(prefix(fmt), #__VA_ARGS__)
#define LOG_DEBUG(fmt,...) log.getLogger()->debug(prefix(fmt), #__VA_ARGS__)

#endif
