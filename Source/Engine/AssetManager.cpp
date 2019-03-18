/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "AssetManager.h"
#include "Collision.h"

AssetManager::AssetManager()
{
}

map<string, sf::Texture*> AssetManager::textures;
map<string, sf::Font*> AssetManager::fonts;
map<string, sf::Music*> AssetManager::musics;
map<string, sf::SoundBuffer*> AssetManager::soundBuffers;
//std::vector<string> AssetManager::order;

/*
// Get Length of Textures Array
int AssetManager::getTexturesLength() {
	return textures.size();
}
*/

//Textures:

// Get Texture by Name
sf::Texture *AssetManager::getTexture(string name)
{

	// See if we have already loaded this texture
	if (textures.find(name) != textures.end()) {
		return textures[name];
	}
	else {
		return NULL;
	}
}




/*
// Get Texture by Index
sf::Texture *AssetManager::getTexture(int index)
{
	// Stay DRY and reuse get by name, but get string name from vector with index
	return getTexture(order.at(index));
}
*/
// Assign a Texture a Name (for accessing via get) and path (to load from)
sf::Texture *AssetManager::loadTexture(string name, string path, string path2)
{
	// Haven't loaded it yet, time to create it
	sf::Texture *texture = new sf::Texture();

	if (texture->loadFromFile(path))
	{
		textures[name] = texture;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return textures[name];
	}
	else if (texture->loadFromFile(path2))
	{
		textures[name] = texture;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return textures[name];
	}
	else
	{
		// Could not load the file
		delete texture;
		return NULL;
	}
}




//Fonts:
// Get Font by Name
sf::Font *AssetManager::getFont(string name)
{

	// See if we have already loaded this font
	if (fonts.find(name) != fonts.end()) {
		return fonts[name];
	}
	else {
		return NULL;
	}
}

// Assign a Font a Name (for accessing via get) and path (to load from)
sf::Font *AssetManager::loadFont(string name, string path, string path2)
{
	// Haven't loaded it yet, time to create it
	sf::Font *font = new sf::Font();

	if (font->loadFromFile(path))
	{
		fonts[name] = font;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return fonts[name];
	}
	else if (font->loadFromFile(path2))
	{
		fonts[name] = font;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return fonts[name];
	}
	else
	{
		// Could not load the file
		delete font;
		return NULL;
	}
}


//Musics:
// Get Music by Name
sf::Music *AssetManager::getMusic(string name)
{

	// See if we have already loaded this music
	if (musics.find(name) != musics.end()) {
		return musics[name];
	}
	else {
		return NULL;
	}
}

// Assign a Music a Name (for accessing via get) and path (to load from)
sf::Music *AssetManager::loadMusic(string name, string path, string path2)
{
	// Haven't loaded it yet, time to create it
	sf::Music *music = new sf::Music();

	if (music->openFromFile(path))
	{
		musics[name] = music;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return musics[name];
	}
	else if (music->openFromFile(path2))
	{
		musics[name] = music;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return musics[name];
	}
	else
	{
		// Could not load the file
		delete music;
		return NULL;
	}
}

//Soundbuffers:
// Get soundbuffer by Name
sf::SoundBuffer *AssetManager::getSoundBuffer(string name)
{

	// See if we have already loaded this soundbuffer
	if (soundBuffers.find(name) != soundBuffers.end()) {
		return soundBuffers[name];
	}
	else {
		return NULL;
	}
}

// Assign a SoundBuffer a Name (for accessing via get) and path (to load from)
sf::SoundBuffer *AssetManager::loadSoundBuffer(string name, string path, string path2)
{
	// Haven't loaded it yet, time to create it
	sf::SoundBuffer *soundBuffer = new sf::SoundBuffer();

	if (soundBuffer->loadFromFile(path))
	{
		soundBuffers[name] = soundBuffer;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return soundBuffers[name];
	}
	else if (soundBuffer->loadFromFile(path2))
	{
		soundBuffers[name] = soundBuffer;

		// Push to vector the order in which items were loaded into map, for accessing via index.
		//order.push_back(name);
		return soundBuffers[name];
	}
	else
	{
		// Could not load the file
		delete soundBuffer;
		return NULL;
	}
}

AssetManager::~AssetManager()
{

	// Delete all of the textures we used
	sf::Texture *texture;
	map<string, sf::Texture*>::iterator iter = textures.begin();
	while (iter != textures.end())
	{
		texture = iter->second;
		delete texture;
		iter++;
	}

	// Delete all of the fonts we used
	sf::Font *font;
	map<string, sf::Font*>::iterator iter2 = fonts.begin();
	while (iter2 != fonts.end())
	{
		font = iter2->second;
		delete font;
		iter2++;
	}

	// Delete all of the music we used
	sf::Music *music;
	map<string, sf::Music*>::iterator iter3 = musics.begin();
	while (iter3 != musics.end())
	{
		music = iter3->second;
		delete music;
		iter3++;
	}

	// Delete all of the soundbuffers we used
	sf::SoundBuffer *soundBuffer;
	map<string, sf::SoundBuffer*>::iterator iter4 = soundBuffers.begin();
	while (iter4 != soundBuffers.end())
	{
		soundBuffer = iter4->second;
		delete soundBuffer;
		iter4++;
	}

}