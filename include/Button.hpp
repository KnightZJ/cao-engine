#include <SFML/Graphics.hpp>

using namespace sf;

class BaseButton : public Drawable {
public:
    enum ButtonStatus {
        Normal,
        Hover,
        Pressed
    };
public:
    BaseButton(Font& font);
    void setTextString(String s);
    void setTextColor(ButtonStatus status, Color color);
    void setPosition(Vector2f pos);
    virtual void update(Event& event);
protected:
    void resize();
    bool contains(int x, int y);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    virtual void setStatus(ButtonStatus status);
protected:
    ButtonStatus m_status;
    Text m_text;
    Color m_text_color[3];
    Font m_text_font;
    int m_text_fontsize;
    Vector2f m_size;
    Vector2f m_pos;
};

class Button : public BaseButton {
public:
    Button(Font &font);
    void setPosition(Vector2f pos);
    void setTextString(String s);

private:
    virtual void draw(RenderTarget& target, RenderStates states) const;
private:
    RectangleShape m_shape;
    void resize();
};