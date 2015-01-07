#ifndef TEXT_H__
#define TEXT_H__

#include "Ref.h"
#include "AnimationTarget.h"
#include "Properties.h"
#include "Font.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Effect.h"
#include "Node.h"

namespace gameplay
{

/**
 * Defines a text block of characters to be drawn.
 *
 * Text can be attached to a node.
 */
class Text : public Ref, public AnimationTarget
{
    friend class Node;
    
public:
    
    /**
     * Opacity property. Data=opacity
     */
    static const int ANIMATE_OPACITY = 1;
    
    /**
     * Color property. Data = red, green, blue, alpha
     */
    static const int ANIMATE_COLOR = 2;

    /**
     * Creates a Text object from a given string.
     * Vertex coordinates, UVs and indices will be computed and stored in the Text object.
     * For static text labels that do not change frequently, this means these computations
     * need not be performed every frame.
     *
     * @param fontPath The font path.
     * @param str The text string to draw.
     * @param color The text color.
     * @param size The font size to draw text (0 for default font size).
     *
     * @return A Text object.
     * @script{ignore}
     */
    static Text* create(const char* fontPath, const wchar_t* str, const Vector4& color = Vector4::one(), unsigned int size = 0);
    
    /**
     * Creates text from a properties object.
     *
     * @param properties The properties object to load from.
     * @return The tile set created.
     */
    static Text* create(Properties* properties);
    
    /**
     * Sets the text to be drawn.
     *
     * @param str The text string to be drawn.
     * @script{ignore}
     */
    void setText(const wchar_t* str);
    
    /**
     * Get the string that will be drawn from this Text object.
     *
     * @return The text string to be drawn.
     * @script{ignore}
     */
    const wchar_t* getText() const;
    
    /**
     * Gets the size of the text to be drawn.
     *
     * @return The size of the text to be drawn.
     */
    unsigned int getSize() const;
    
    /**
     * Set the width to draw the text within.
     *
     * @param width The width to draw the text.
     */
    void setWidth(float width);
    
    /**
     * Gets the width of the text.
     *
     * @return The width of the text.
     */
    float getWidth() const;
    
    /**
     * Set the height of text to be drawn within.
     *
     * @param height The height to draw the text.
     */
    void setHeight(float height);
    
    /**
     * Gets the width of the text.
     *
     * @return The overall width of the text.
     */
    float getHeight() const;
    
    /**
     * Sets if the the text is wrapped by the text width.
     * 
     * @param wrap true if the the text is wrapped by the text width.
     */
    void setWrap(bool wrap);
    
    /**
     * Gets if the the text is wrapped by the text width.
     *
     * Default is true.
     *
     * @return true if the the text is wrapped by the text width.
     */
    bool getWrap() const;
    
    /**
     * Sets if the text is rendered right-to-left.
     *
     * @param rightToLeft true if the text is rendered right-to-left, false if left-to-right.
     */
    void setRightToLeft(bool rightToLeft);
    
    /**
     * Sets if the text is rendered right-to-left.
     *
     * Default is false (left-to-right)
     * @return rightToLeft true if the text is rendered right-to-left, false if left-to-right.
     */
    bool getRightToLeft() const;
    
    /**
     * Sets the justification to align the text within the text bounds.
     *
     * @param align The text justification alignment.
     */
    void setJustify(Font::Justify align);

    /**
     * Gets the justification to align the text within the text bounds.
     *
     * @return The text justification alignment.
     */
    Font::Justify getJustify() const;
    
    /**
     * Sets the local clipping region for this text.
     *
     * This is used for clipping unwanted regions of text.
     *
     * @param clip The clipping region for this text.
     */
    void setClip(const Rectangle& clip);
    
    /**
     * Gets the local clipping region for this text.
     *
     * This is used for clipping unwanted regions of text.
     *
     * Default is Rectangle(0, 0, 0, 0) which means no clipping region is applied.
     *
     * @param clip The clipping region for this text.
     */
    const Rectangle& getClip() const;
    
    /**
     * Sets the opacity for the sprite.
     *
     * The range is from full transparent to opaque [0.0,1.0].
     *
     * @param opacity The opacity for the sprite.
     */
    void setOpacity(float opacity);
    
    /**
     * Gets the opacity for the sprite.
     *
     * The range is from full transparent to opaque [0.0,1.0].
     *
     * @preturn The opacity for the sprite.
     */
    float getOpacity() const;
    
    /**
     * Sets the color (RGBA) for the sprite.
     *
     * @param color The color(RGBA) for the sprite.
     */
    void setColor(const Vector4& color);
    
    /**
     * Gets the color (RGBA) for the sprite.
     *
     * @return The color(RGBA) for the sprite.
     */
    const Vector4& getColor() const;
    
    /**
     * Gets the node that this sprite is attached to.
     *
     * @return The node that this sprite is attached to.
     */
    Node* getNode() const;
   
    /**
     * Draws the text.
     */
    unsigned int draw();
    
protected:
    /**
     * Constructor
     */
    Text();

    /**
     * Destructor
     */
    ~Text();

    /**
     * operator=
     */
    Text& operator=(const Text& text);
    
    /**
     * Sets the node this sprite is attached to.
     */
    void setNode(Node* node);
    
    /**
     * @see AnimationTarget::getAnimationPropertyComponentCount
     */
    unsigned int getAnimationPropertyComponentCount(int propertyId) const;
    
    /**
     * @see AnimationTarget::getAnimationProperty
     */
    void getAnimationPropertyValue(int propertyId, AnimationValue* value);
    
    /**
     * @see AnimationTarget::setAnimationProperty
     */
    void setAnimationPropertyValue(int propertyId, AnimationValue* value, float blendWeight = 1.0f);
    
    Text* clone(NodeCloneContext &context);
    
    void cloneInto(Text* text, NodeCloneContext &context) const;

    Font* _font;
    std::wstring _text;
    unsigned int _size;
    float _width;
    float _height;
    bool _wrap;
    bool _rightToLeft;
    Font::Justify _align;
    Rectangle _clip;
    float _opacity;
    Vector4 _color;
    Node* _node;
};
    
}

#endif
