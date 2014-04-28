#include "event_manager.h"
#include "gpl_assert.h"
using namespace std;

/* static */ Event_manager *Event_manager::m_instance = 0;

/* static */ Event_manager * Event_manager::instance()
{
  if (!m_instance)
    m_instance = new Event_manager();
  return m_instance;
}

void Event_manager::add_block(int keystroke, Statement_block* block) {
    block_handler[keystroke].push_back(block);
}

Event_manager::Event_manager()
{
}

Event_manager::~Event_manager()
{
}


void 
Event_manager::execute_handlers(Window::Keystroke keystroke)
{
     for (std::vector<Statement_block*>::iterator it =
        block_handler[keystroke].begin();
        it != block_handler[keystroke].end(); it++)
        (*it)->execute();
}
