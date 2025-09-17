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

int EventHandler::handleEvent(Event* e){
    return 0;
}
