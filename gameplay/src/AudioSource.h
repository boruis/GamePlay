/*
    Copyright 2016 Andrew Karpushin (reven86@gmail.com).

    This source file is a Derivative Work from orignal Gameplay3D source files.
    The Gameplay3D project is distributed under the terms of Apache 2.0 License.
    Original Gameplay3D source files can be found at https://github.com/gameplay3d/GamePlay

    Changes to orginal document were done in lines: 165.
*/


#ifndef AUDIOSOURCE_H_
#define AUDIOSOURCE_H_

#include "Vector3.h"
#include "Ref.h"
#include "Transform.h"

namespace gameplay
{

class AudioBuffer;
class Node;
class NodeCloneContext;

/**
 * Defines an audio source in 3D space.
 *
 * This can be attached to a Node for applying its 3D transformation.
 *
 * @see http://gameplay3d.github.io/GamePlay/docs/file-formats.html#wiki-Audio
 */
class AudioSource : public Ref, public Transform::Listener
{
public:

    friend class Node;
    friend class AudioController;

    /**
     * The audio source's audio state.
     */
    enum State
    {
        INITIAL,
        PLAYING,
        PAUSED,
        STOPPED
    };

    /**
     * Create an audio source. This is used to instantiate an Audio Source. Currently only wav, au, and raw files are supported.
     * Alternately, a URL specifying a Properties object that defines an audio source can be used (where the URL is of the format
     * "<file-path>.<extension>#<namespace-id>/<namespace-id>/.../<namespace-id>" and "#<namespace-id>/<namespace-id>/.../<namespace-id>" is optional).
     * 
     * @param url The relative location on disk of the sound file or a URL specifying a Properties object defining an audio source.
     * @param streamed Don't read the entire audio buffer first before playing, instead play immediately from a stream that is read on demand.
     * @return The newly created audio source, or NULL if an audio source cannot be created.
     * @script{create}
     */
    static AudioSource* create(const char* url, bool streamed = false);

    /**
     * Create an audio source from the given properties object.
     * 
     * @param properties The properties object defining the audio source (must have namespace equal to 'audio').
     * @return The newly created audio source, or <code>NULL</code> if the audio source failed to load.
     * @script{create}
     */
    static AudioSource* create(Properties* properties);

    /**
     * Plays the audio source.
     */
    void play();

    /**
     * Pauses the playing of the audio source.
     */
    void pause();

    /**
     * Resumes playing of the audio source.
     */
    void resume();

    /**
     * Stops the playing of the audio source.
     */
    void stop();

    /**
     * Rewinds the audio source to the beginning.
     */
    void rewind();

    /**
     * Gets the current state of the audio source.
     *
     * @return PLAYING if the source is playing, STOPPED if the source is stopped, PAUSED if the source is paused and INITIAL otherwise.
     */
    AudioSource::State getState() const;

    /**
     * Determines whether the audio source is streaming or not.
     *
     * @return true if the audio source is streaming, false if not.
     */
    bool isStreamed() const;

    /**
     * Determines whether the audio source is looped or not.
     *
     * @return true if the audio source is looped, false if not.
     */
    bool isLooped() const;

    /**
     * Sets the state of the audio source to be looping or not.
     *
     * @param looped true to loop the sound, false to not loop it.
     */
    void setLooped(bool looped);

    /**
     * Returns the gain of the audio source.
     *
     * @return The gain.
     */
    float getGain() const;

    /**
     * Sets the gain/volume of the audio source.
     *
     * @param gain The gain/volume of the source.
     */
    void setGain(float gain);

    /**
     * Returns the pitch of the audio source.
     *
     * @return The pitch.
     */
    float getPitch() const;

    /**
     * Sets the pitch of the audio source.
     *
     * @param pitch The pitch of the source.
     */
    void setPitch(float pitch);

    /**
     * Gets the velocity of the audio source.
     *
     * @return The velocity as a vector.
     */
    const Vector3& getVelocity() const;

    /**
     * Sets the velocity of the audio source.
     *
     * @param velocity A vector representing the velocity.
     */
    void setVelocity(const Vector3& velocity);

    /**
     * Sets the velocity of the audio source.
     *
     * @param x The x coordinate of the velocity.
     * @param y The y coordinate of the velocity.
     * @param z The z coordinate of the velocity.
     */
    void setVelocity(float x, float y, float z);

    /**
     * Gets the playback offset of the audio source.
     *
     * @return The source current playing time in seconds.
     */
    float getOffsetInSeconds() const;

    /**
     * Sets the playback offset of the audio source.
     *
     * @param offset The source playing time in seconds.
     */
    void setOffsetInSeconds( float offset );

    /**
     * Gets the node that this source is attached to.
     * 
     * @return The node that this audio source is attached to.
     */
    Node* getNode() const;

private:

    /**
     * Constructor that takes an AudioBuffer.
     */
    AudioSource(AudioBuffer* buffer, ALuint source);

    /**
     * Destructor.
     */
    virtual ~AudioSource();

    /**
     * Hidden copy assignment operator.
     */
    AudioSource& operator=(const AudioSource&);

    /**
     * Sets the node for this audio source.
     */
    void setNode(Node* node);

    /**
     * @see Transform::Listener::transformChanged
     */
    void transformChanged(Transform* transform, long cookie);

    /**
     * Clones the audio source and returns a new audio source.
     * 
     * @param context The clone context.
     * @return The newly created audio source.
     */
    AudioSource* clone(NodeCloneContext& context);

    bool streamDataIfNeeded();

    ALuint _alSource;
    AudioBuffer* _buffer;
    bool _looped;
    float _gain;
    float _pitch;
    Vector3 _velocity;
    Node* _node;
};

}

#endif
