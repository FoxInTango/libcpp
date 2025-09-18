#include "event.h"
using namespace foxintango;
#include <typeinfo>
#include <string>

Event::Event(){
}

Event::~Event() {
}

EventHandler::EventHandler(){}
EventHandler::~EventHandler(){}
int EventHandler::handleEvent(Event* event){ return 0; }

EventSessionInterface::EventSessionInterface(){}
EventSessionInterface::~EventSessionInterface(){}

const char* EventSessionInterface::getAttribute(const char* const name){
    return 0;
}
