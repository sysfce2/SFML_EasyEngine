#pragma once

#include <SFML/Graphics.hpp>
#include "Vec2.h"

/*
Class representing an animation.
*/
class Animation
{
	sf::Sprite	_sprite;
	int			_frameCount		= 0;			//number of frames in animation
	int			_currentFrame	= 0;			//current frame of the animation
	int			_speed			= 0;			//speed of animation playback
	Vec2		_offset			= { 0 , 0 };	//starting position in the sprite sheet
	Vec2		_size			= { 1, 1 };		//size of the animation frame
	std::string	_name			= "None";
	bool		_hasEnded		= false;
	int			_animFrame		= 0;

	
	void onEnd();


public:
	Animation();

	/*
	\param name: name of the animation
	\param textureName: name of the texture to be used (must be loaded to game assets)
	\param frameCount: number of frames in the animation
	\param speed: number of frames in game between frames of animation (the lower, the faster the animation will play)
	\param offset: the position of the animation within the texture
	\param size: size of the animation rectangle within the texture
	*/
	Animation(	const std::string& name, 
				const sf::Texture& t, 
				int frameCount, 
				int speed,
				const Vec2& offset,
				const Vec2& size);

	/*
	Update the animation. Should be called on each frame as it will take speed into account.
	*/
	void update();

	/*
	Return the state of the animation.
	/return 1 if animation ha ended, 0 if not
	*/
	bool hasEnded() const;

	/*
	Get the name of the animation.
	/return const reference to the name of the animation
	*/
	const std::string& getName() const;

	/*
	Get the size of the animation (in texture coordinates)
	\return const Vec2 size in pixels
	*/
	const Vec2& getSize() const;

	/*
	Get the animation sprite.
	/return reference to the animation sprite
	*/
	sf::Sprite& getSprite();

	/*
	Get the speed of the animation.
	/return speed
	*/
	const int getInterval() const;

	/*
	Set a new speed for the animation.
	/param interval: number of game frames between each frame of animation
	*/
	void setInterval(int interval);
};