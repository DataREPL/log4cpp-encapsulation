#include "Mylog.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

Mylog* Mylog::plog_ = NULL;

Mylog & Mylog::getInstance()
{
	if(plog_ == NULL)
	{
		plog_ = new Mylog;
	}
	return *plog_;
}

void Mylog::destroy()
{
	if(plog_)
	{
		plog_->catRef_.info("Mylog destroy");
		plog_->catRef_.shutdown();
		delete plog_;
	}
}


Mylog::Mylog()
	: catRef_(log4cpp::Category::getRoot())
{
	log4cpp::PatternLayout *pPtnLyt1 = 
		new log4cpp::PatternLayout;
	pPtnLyt1->setConversionPattern("%d: %p %c %x:%m%n");

	log4cpp::PatternLayout *pPtnLyt2 = 
		new log4cpp::PatternLayout;
	pPtnLyt2->setConversionPattern("%d: %p %c %x:%m%n");
	
	log4cpp::OstreamAppender *pOsAppder = 
		new log4cpp::OstreamAppender("osAppender", &std::cout);
	pOsAppder->setLayout(pPtnLyt1);

	log4cpp::FileAppender * pFileAppder =
		new log4cpp::FileAppender("fileAppender", "./mylog.txt");
	pFileAppder->setLayout(pPtnLyt2);

	catRef_.setPriority(log4cpp::Priority::DEBUG);
	catRef_.addAppender(pOsAppder);
	catRef_.addAppender(pFileAppder);

}

void Mylog::setPriority(Priority priority)
{
	switch(priority)
	{
	case (ERROR):
		catRef_.setPriority(log4cpp::Priority::ERROR);
		break;
	case (WARN):
		catRef_.setPriority(log4cpp::Priority::WARN);
		break;
	case (INFO):
		catRef_.setPriority(log4cpp::Priority::INFO);
		break;
	case (DEBUG):
		catRef_.setPriority(log4cpp::Priority::DEBUG);
		break;
	default:
		catRef_.setPriority(log4cpp::Priority::DEBUG);
		break;
	}
}

log4cpp::Category* Mylog::getLogger() {
    return &catRef_;
}
