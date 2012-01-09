#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include "Base.h"
#include "RenderTarget.h"
#include "DepthStencilTarget.h"

namespace gameplay
{

class FrameBuffer : public Ref
{
public:

    /**
     * Creates an empty FrameBuffer and adds it to the list of available FrameBuffers.
     *
     * @param id The ID of the new FrameBuffer.  Uniqueness is recommended but not enforced.
     *
     * @return A newly created FrameBuffer.
     */
    static FrameBuffer* create(const char* id);

    /**
     * Creates a new FrameBuffer with a RenderTarget of the specified width and height,
     * and adds the FrameBuffer to the list of available FrameBuffers.
     *
     * @param id The ID of the new FrameBuffer.  Uniqueness is recommended but not enforced.
     * @param width The width of the RenderTarget to be created and attached.
     * @param height The height of the RenderTarget to be created and attached.
     *
     * @return A newly created FrameBuffer.
     */
    static FrameBuffer* create(const char* id, unsigned int width, unsigned int height);

    /**
     * Get a named FrameBuffer from its ID.
     *
     * @param id The ID of the FrameBuffer to search for.
     *
     * @return The FrameBuffer with the specified ID, or NULL if one was not found.
     */
    static FrameBuffer* getFrameBuffer(const char* id);

    /**
     * Get the ID of this FrameBuffer.
     *
     * @return The ID of this FrameBuffer.
     */
    const char* getID() const;

    /**
     * Get the number of color attachments available on the current hardware.
     *
     * @return The number of color attachments available on the current hardware.
     */
    static unsigned int getMaxRenderTargets();
 
    /**
     * Set a RenderTarget on this FrameBuffer's color attachment at the specified index.
     *
     * @param target The RenderTarget to set.
     * @param index The index of the color attachment to set.
     */
    void setRenderTarget(RenderTarget* target, unsigned int index = 0);
 
    /**
     * Get the RenderTarget attached to the FrameBuffer's color attachment at the specified index.
     *
     * @param index The index of the color attachment to retrieve a RenderTarget from.
     *
     * @return The RenderTarget attached at the specified index.
     */
    RenderTarget* getRenderTarget(unsigned int index = 0) const;
 
    /**
     * Set this FrameBuffer's DepthStencilTarget.
     *
     * @param target The DepthStencilTarget to set on this FrameBuffer.
     */
    void setDepthStencilTarget(DepthStencilTarget* target);
  
    /**
     * Get this FrameBuffer's DepthStencilTarget.
     *
     * @return This FrameBuffer's DepthStencilTarget.
     */
    DepthStencilTarget* getDepthStencilTarget() const;
 
    /**
     * Binds this FrameBuffer for off-screen rendering.
     */
    void bind();

    /**
     * Binds the default FrameBuffer for rendering to the display.
     */
    static void bindDefault(); 
     
private:
 
    FrameBuffer(const char* id);

    /**
     * Destructor.  Removes this FrameBuffer from the list of available FrameBuffers.
     */
    ~FrameBuffer();

    std::string _id;
    FrameBufferHandle _handle;
    RenderTarget** _renderTargets;
    DepthStencilTarget* _depthStencilTarget;
};

}

#endif