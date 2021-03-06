/*
	Button.h - Slimmer
	Copyright (C) 2016-2017  Terényi, Balázs (terenyi@freemail.hu)

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "EventHandler.h"
#define EV_STANDALONE 1
#include "libev/ev++.h"

class Button
{
public:
	enum ButtonEvent {PRESS, RELEASE, REPEAT};

	Button(EventHandler* const parent, const unsigned short key,
		   const EventHandler::Event shortEvent,
		   const EventHandler::Event longEvent = EventHandler::NONE,
		   const EventHandler::Event repeatEvent = EventHandler::NONE);

	void handleKey(const ButtonEvent event, const unsigned short key);

protected:
	void longPressTimeout();

protected:
	EventHandler* const mParent;
	const unsigned short mKey;
	ev::timer mPressTimer;
	const EventHandler::Event mShortEvent;
	const EventHandler::Event mLongEvent;
	const EventHandler::Event mRepeatEvent;
};

#endif // BUTTON_H
