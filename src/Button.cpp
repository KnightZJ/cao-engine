#include "Button.hpp"

BaseButton::BaseButton(Font& font) {
    m_status = Normal;
    setTextColor(Normal, Color::Black);
    setTextColor(Hover, Color::Blue);
    setTextColor(Pressed, Color::Red);
    m_text = Text();
    m_text_font = font;
    m_text.setFont(m_text_font);
    m_text.setColor(m_text_color[Normal]);
    resize();
    m_text.setOrigin(m_size.x/2, m_size.y/2);
    setPosition({100, 100});
}

void BaseButton::update(Event& event) {
    switch(event.type) {
        case Event::MouseMoved:
            if(contains(event.mouseMove.x, event.mouseMove.y)) {
                if(m_status != Pressed)
                    setStatus(Hover);
            }
            else {
                setStatus(Normal);
            }
            break;
        case Event::MouseButtonPressed:
            if(contains(event.mouseButton.x, event.mouseButton.y)) {
                setStatus(Pressed);
            break;
        case Event::MouseButtonReleased:
            if(contains(event.mouseButton.x, event.mouseButton.y)) {
                setStatus(Hover);
            }
            else
                setStatus(Normal);
            break;
        }
    }
}

void BaseButton::draw(RenderTarget& target, RenderStates states) const {
    target.draw(m_text);
}

void BaseButton::setStatus(ButtonStatus status) {
    if(m_status != status) {
        m_status = status;
        m_text.setColor(m_text_color[status]);
    }
}

void BaseButton::setTextColor(ButtonStatus status, Color color) {
    m_text_color[status] = color;
}

void BaseButton::setTextString(String s) {
    m_text.setString(s);
    resize();
}

void BaseButton::resize() {
    FloatRect rect = m_text.getGlobalBounds();
    m_size = {rect.width+60, rect.height+30};
    m_text.setOrigin(rect.width/2, rect.height/2);
}

bool BaseButton::contains(int x, int y) {
    return x > m_pos.x - m_size.x/2 && x < m_pos.x + m_size.x/2
        && y > m_pos.y - m_size.y/2 && y < m_pos.y + m_size.y/2;
}

void BaseButton::setPosition(Vector2f pos) {
    m_pos = pos;
    m_text.setPosition(pos);
}

Button::Button(Font& font) : BaseButton(font) {
    m_shape.setOrigin(m_size.x/2, m_size.y/2);
    m_shape.setFillColor(Color::Yellow);
    m_shape.setPosition(m_pos);
    m_shape.setSize(m_size);
}

void Button::draw(RenderTarget& target, RenderStates states) const {
    target.draw(m_shape);
    BaseButton::draw(target, states);
}

void Button::setPosition(Vector2f pos) {
    BaseButton::setPosition(pos);
    m_shape.setPosition(pos);
}

void Button::resize() {
    BaseButton::resize();
    m_shape.setSize(m_size);
    m_shape.setOrigin(m_size.x/2, m_size.y/2);
}

void Button::setTextString(String s) {
    m_text.setString(s);
    resize();
    
}