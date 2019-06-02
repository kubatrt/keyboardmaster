#include "Metronome.hpp"

namespace km
{

Metronome::Metronome(unsigned int bpm)
	: bpm_(bpm)
	, isPlaying_(false)
	, tick_(0)
{
}

void Metronome::start()
{
	timer_.restart();
	isPlaying_ = true;
	tick_ = 0;
}

void Metronome::stop()
{
	elapsedTime_ = timer_.restart();
	isPlaying_ = false;
}

void Metronome::update(sf::Time deltaTime)
{
	if(!isPlaying_)
		return;

	elapsedTime_ = timer_.getElapsedTime();
	sf::Time interval(sf::seconds(60.f / bpm_));
	if (elapsedTime_ >= interval)
	{
		elapsedTime_ = sf::Time::Zero;
		playSound();
	}

}

void Metronome::playSound()
{
	tick_++;
	if(tick_ % tickSeparator_ )
	{

	}
	else
	{

	}
}

}