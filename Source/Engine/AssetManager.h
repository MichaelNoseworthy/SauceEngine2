#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>

using namespace std;

class AssetManager
{
	// The textures that are loaded
	static map<string, sf::Texture*> textures;
	// The fonts that are loaded
	static map<string, sf::Font*> AssetManager::fonts;
	// The music that are loaded
	static map<string, sf::Music*> AssetManager::musics;
	// The sound that are loaded
	static map<string, sf::SoundBuffer*> AssetManager::soundBuffers;

	// Manually keep track of the order in which textures were loaded, so you can get by index.
	//static std::vector<string> order;

	// Constructor that is not used
	AssetManager();
public:
	// Destructor which deletes the textures previously loaded
	~AssetManager();

	//static int getTexturesLength();

	// Get texutre by name specified in loadTexture, or return null
	static sf::Texture *getTexture(string name);

	// Get font by name specified in loadFont, or return null
	static sf::Font *getFont(string name);

	// Get music by name specified in loadMusic, or return null
	static sf::Music *getMusic(string name);

	// Get sound by name specified in loadSoundBuffer, or return null
	static sf::SoundBuffer *getSoundBuffer(string name);

	// Get texutre by index in map, or return null
	//static sf::Texture *getTexture(int index);

	// Loads the texture and returns a pointer to it
	// If it is already loaded, this function just returns it
	// If it cannot find the file, returns NULL
	static sf::Texture *loadTexture(string name, string path, string path2);

	// Loads the font and returns a pointer to it
	// If it is already loaded, this function just returns it
	// If it cannot find the file, returns NULL
	static sf::Font *loadFont(string name, string path, string path2);

	// Loads the music and returns a pointer to it
	// If it is already loaded, this function just returns it
	// If it cannot find the file, returns NULL
	static sf::Music *loadMusic(string name, string path, string path2);

	// Loads the sound and returns a pointer to it
	// If it is already loaded, this function just returns it
	// If it cannot find the file, returns NULL
	static sf::SoundBuffer *loadSoundBuffer(string name, string path, string path2);
};

#endif