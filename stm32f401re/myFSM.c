typedef enum {
	IDLE_STATE,
	COIN_INSERTED_STATE,
	OPTION_SELECTED_STATE,
	MAX_STATES
} state_e;

typedef enum {
	INSERT_COIN_EVENT,
	SELECT_OPTION_EVENT,
	COFFEE_READY_EVENT,
	MAX_EVENTS
} event_e;

state_e state = IDLE_STATE;
state_e next_state;
event_e event;

while(1)
{
	event = read_event();
	if (state == IDLE_STATE)
	{
		if(event == INSERT_COIN_EVENT)
		{
			next_state = insert_coin_event_handler();
		}
	}
	else if(state == COIN_INSERTED_STATE)
	{
		if(event == SELECT_OPTION_EVENT)
		{
			next_state = select_option_event_handler();
		}
	}
	else if(state == OPTION_SELECTED_STATE)
	{
		if(event == COFFEE_READY_EVENT)
		{
			next_state = coffee_ready_event_handler();
		}
	}
	state = next_state; 
}
