/*
 *  Map.h
 *  openc2e
 *
 *  Created by Alyssa Milburn on Tue May 25 2004.
 *  Copyright (c) 2004 Alyssa Milburn. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 */

#ifndef _OPENC2E_MAP_H
#define _OPENC2E_MAP_H

#include "physics.h"
#include "serfwd.h"

#include <memory>
#include <string>
#include <vector>

class Room;
class MetaRoom;

class Map {
  protected:
	FRIEND_SERIALIZE(Map)
	unsigned int width, height;
	std::vector<std::unique_ptr<MetaRoom>> metarooms;
	std::vector<std::shared_ptr<Room>> rooms;

	friend class MetaRoom;

  public:
	/* Get a room, any room.
	 *
	 * For those times when you really, really need a room.
	 */
	MetaRoom* getFallbackMetaroom();

	unsigned int room_base, metaroom_base;

	Map();
	~Map();

	void Reset();
	void SetMapDimensions(unsigned int, unsigned int);
	unsigned int getWidth() { return width; }
	unsigned int getHeight() { return height; }

	MetaRoom* addMetaRoom(int x, int y, int width, int height, const std::string& background, bool wrap = false);
	MetaRoom* getMetaRoom(unsigned int);

	bool hasDoor(const std::shared_ptr<Room>& r1, const std::shared_ptr<Room>& r2);
	void setDoorPerm(const std::shared_ptr<Room>& r1, const std::shared_ptr<Room>& r2, int perm);
	int getDoorPerm(const std::shared_ptr<Room>& r1, const std::shared_ptr<Room>& r2);

	unsigned int getMetaRoomCount();
	std::shared_ptr<Room> getRoom(unsigned int);
	unsigned int getRoomCount();

	MetaRoom* metaRoomAt(unsigned int, unsigned int);
	std::shared_ptr<Room> roomAt(float, float);
	std::vector<std::shared_ptr<Room>> roomsAt(float, float);

	bool collideLineWithRoomSystem(Point src, Point dest, std::shared_ptr<Room>& room, Point& where, Line& wall, unsigned int& walldir, int perm);
	bool collideLineWithRoomBoundaries(Point src, Point dest, std::shared_ptr<Room> room, std::shared_ptr<Room>& newroom, Point& where, Line& wall, unsigned int& walldir, int perm);

	void tick();
};

#endif
/* vim: set noet: */
