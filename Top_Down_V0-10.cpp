#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>
#include <utility>

#include <SFML/Graphics.hpp>

void origin_from_text(sf::Text& text)
{
    
    const sf::FloatRect rectangle{text.getLocalBounds()};
    
    text.setOrigin(0.5f*rectangle.width, 0.95f*rectangle.height);
    
}

struct name_entity
{
    
    // name in text form
    
    const std::string m_entity_name{"Asuka"};
    
    sf::Font m_font;
    
    const std::string m_font_name{"VeraMono-Bold.ttf"};
    
    const float m_text_size{20.0f};
    
    sf::Vector2f m_position{0.0f, 0.0f};
    
    const sf::Color m_color{255, 255, 255};
    
    sf::Text m_text;
    
    name_entity(const std::string& name, const float size, const sf::Vector2f& posit, const sf::Color& color);
    
    ~name_entity();
        
};

name_entity::name_entity(const std::string& name, const float size, const sf::Vector2f& posit, const sf::Color& color)
    :m_entity_name(name), m_font(), m_text_size(size), m_position(posit), m_color(color), m_text()
{
    
    assert(m_entity_name != "");    
    assert(m_text_size > 0.0f);
    assert(m_font_name != "");
    assert(m_position.x > 0.0f);
    assert(m_position.y > 0.0f);
    
    if (!m_font.loadFromFile(m_font_name))
    {
            
        std::cout << m_font_name << " not found!\n";        
        std::cout << "Error -2\n";        
        exit (EXIT_FAILURE);
            
    }
    
    m_text.setFont(m_font);
    m_text.setCharacterSize(m_text_size);    
    m_text.setColor(m_color);    
    m_text.setString(m_entity_name);    
    origin_from_text(m_text);    
    m_text.setPosition(m_position);
    
}

name_entity::~name_entity()
{
    
}

void show_name_ent(sf::RenderWindow& window, const name_entity& nament)
{
    
    window.draw(nament.m_text);
    
}

std::wstring value_to_wstring(const float value)
{

    std::wstringstream wstringer;
    
    const int centurion{static_cast<int>(100*value)};
    
    wstringer << L"€" << centurion/100 << ".";
    
    if (abs(centurion)%100 < 10)
    {
        
        wstringer << 0;
        
    }    
    
    wstringer << abs(centurion)%100;
            
    return wstringer.str();
    
}

struct value_entity
{
    
    float m_value{100};
    
    std::wstring m_value_name{value_to_wstring(m_value)};
    
    sf::Font m_font;
    
    const std::string m_font_name{"VeraMono-Bold.ttf"};
    
    const float m_text_size{20.0f};
    
    sf::Vector2f m_position{0.0f, 0.0f};
    
    sf::Color m_color{255, 255, 255};
    
    sf::Text m_text;
    
    value_entity(const float value, const float size, const sf::Vector2f& posit, const sf::Color& color);
    
    ~value_entity();
    
};




value_entity::value_entity(const float value, const float size, const sf::Vector2f& posit, const sf::Color& color)
    :m_value(value), m_value_name(value_to_wstring(m_value)), m_font(),
    m_text_size(size), m_position(posit), m_color(color), m_text()
{
    
    assert(m_value_name != L"");    
    assert(m_text_size > 0.0f);
    assert(m_font_name != "");
    assert(m_position.x > 0.0f);
    assert(m_position.y > 0.0f);
    
    if (!m_font.loadFromFile(m_font_name))
    {
            
        std::cout << m_font_name << " not found!\n";        
        std::cout << "Error -2\n";        
        exit (EXIT_FAILURE);
            
    }
    
    m_text.setFont(m_font);
    m_text.setCharacterSize(m_text_size);    
    m_text.setColor(m_color);    
    m_text.setString(m_value_name);    
    origin_from_text(m_text);    
    m_text.setPosition(m_position);
    
}

value_entity::~value_entity()
{
    
}

void revalue_valuent(value_entity& valuent, const float value)
{
    
    valuent.m_value = value;
    valuent.m_value_name = value_to_wstring(valuent.m_value);
    valuent.m_text.setString(valuent.m_value_name);    
    origin_from_text(valuent.m_text);    
    // valuent.m_text.setPosition(valuent.m_position);
    
}

void show_value_ent(sf::RenderWindow& window, const value_entity& valuent)
{
    
    window.draw(valuent.m_text);
    
}

struct tria_ent
{
    
    // triangle
    
};

float sqrt_value_tot_radius(const float value, const float norm_radius)
{
    
    assert(norm_radius > 0.0f);
    
    const float norm_value{100.0f};
    assert(norm_value > 0.0f);
    
    return (sqrt(abs(value) + 0.01)/norm_value)*norm_radius;
    
}

float clog_value_tot_radius(const float value, const float norm_radius)
{
    
    assert(norm_radius > 0.0f);
    
    const float norm_value{0.01f};
    assert(norm_value > 0.0f);
    
    return log10((std::abs(value) + 0.011)/norm_value)*norm_radius;
    
}

sf::Color value_to_color(const float value)
{
    
    const float min_value{-0.005f};
    assert(min_value > -0.01f);
    assert(min_value < 0.0f);
    
    const sf::Color red{255, 0, 0};
    const sf::Color green{0, 255, 0};
    
    sf::Color color;
    
    if (value > min_value)
    {
        
        color = green;
        
    }
    else
    {
        
        color = red;
    
    }
    
    return color;
    
}

struct circle_entity
{
    
    float m_value{100.0f};
    
    float m_norm_radius{20.0f};
    
    float m_radius{sqrt_value_tot_radius(m_value, m_norm_radius)};
    
    sf::Vector2f m_position{0.0f, 0.0f};
    
    sf::Color m_color{value_to_color(m_value)};
    
    sf::CircleShape m_circle{m_radius};
    
    circle_entity(const double value, const double norm_radius, const sf::Vector2f& position);
    
    ~circle_entity();
    
};

void set_circle(sf::CircleShape& circle, const float value, const float norm_radius,
                const sf::Vector2f& position, const sf::Color& color)
{
    
    const float radius{sqrt_value_tot_radius(value, norm_radius)};
    
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    
}

circle_entity::circle_entity(const double value, const double norm_radius, const sf::Vector2f& position)
    :m_value(value), m_norm_radius(norm_radius), m_radius(sqrt_value_tot_radius(m_value, m_norm_radius)),
    m_position(position), m_color(value_to_color(m_value)), m_circle(m_radius)
{
	
	assert(m_norm_radius > 0.0f);
	assert(m_position.x > m_radius);
	assert(m_position.y > m_radius);
    
    set_circle(m_circle, m_value, m_norm_radius, m_position, m_color);

}

circle_entity::~circle_entity()
{
    
}

void revalue_circlent(circle_entity& circlent, const float value)
{
    
    circlent.m_value = value;
    
    circlent.m_color = value_to_color(circlent.m_value);
    
    set_circle(circlent.m_circle, circlent.m_value, circlent.m_norm_radius,
            circlent.m_position, circlent.m_color);
    
}

void show_circle_ent(sf::RenderWindow& window, const circle_entity& circlent)
{
    
    window.draw(circlent.m_circle);
    
}

struct circle_collection
{
    
    float m_value{100.0f};
    
    float m_norm_radius{20.0f};
    
    const float m_text_size{20.0f};
    
    const std::string m_name{"Name"};
    
    const float m_circle_mult{1.0f};
    
    const float m_text_mult{0.7f};
    
    const float m_dist{m_circle_mult*sqrt_value_tot_radius(m_value, m_norm_radius) +
                    m_text_mult*m_text_size};  ////  m_mult*sqrt_value_tot_radius(m_value, m_norm_radius)
    
    sf::Vector2f m_jump{0.0f, m_dist};
    
    sf::Vector2f m_position{0.0f, 0.0f};
    
    sf::Color m_color{255, 255, 255};
    
    name_entity m_nament{m_name, m_text_size, m_position - m_jump, m_color};
    
    circle_entity m_circlent{m_value, m_norm_radius, m_position};
    
    value_entity m_valuent{m_value, m_text_size, m_position + m_jump, m_color};
    
    circle_collection(const float value, const float norm_radius, const float text_size,
                            const std::string& name, const sf::Vector2f& position);
                            
    ~circle_collection();
    
};

circle_collection::circle_collection(const float value, const float norm_radius, const float text_size,
                            const std::string& name, const sf::Vector2f& position)
    :m_value(value), m_norm_radius(norm_radius), m_text_size(text_size), m_name(name),
    m_dist(m_circle_mult*sqrt_value_tot_radius(m_value, m_norm_radius) +
            m_text_mult*m_text_size),
    m_jump(0.0f, m_dist), m_position(position),
    m_nament(m_name, m_text_size, m_position - m_jump, m_color),
    m_circlent(m_value, m_norm_radius, m_position),
    m_valuent(m_value, m_text_size, m_position + m_jump, m_color)
{
     
    assert(m_name != "");
    assert(m_norm_radius > 0.0f);
	assert(m_text_size > 0.0f);	
	assert(m_circle_mult > 0.0f);
	assert(m_text_mult > 0.0f);
	assert(m_position.x > sqrt_value_tot_radius(m_value, m_norm_radius));
	assert(m_position.y > sqrt_value_tot_radius(m_value, m_norm_radius));
	
        
}

void show_circolle(sf::RenderWindow& window, const circle_collection& circolle)
{
    
    show_circle_ent(window, circolle.m_circlent);
    show_name_ent(window, circolle.m_nament);
    show_value_ent(window, circolle.m_valuent);
    
}

circle_collection::~circle_collection()
{
        
}

struct rectangle_entity
{
   
    const std::string m_name{"Name"};
    
    sf::Vector2f m_position{0.0f, 0.0f};
    
    const sf::Vector2f m_dimensions{200.0f, 100.0f};
    
    const sf::Color m_color{127, 127, 63};
    
    sf::RectangleShape m_rectangle{m_dimensions};
     
    rectangle_entity(const std::string& name, const sf::Vector2f& position,
                     const sf::Vector2f& dimensions);
              
    ~rectangle_entity();
    
};

rectangle_entity::rectangle_entity(const std::string& name, const sf::Vector2f& position,
                                   const sf::Vector2f& dimensions)
    :m_name(name), m_position(position), m_dimensions(dimensions), m_rectangle(m_dimensions)
{
	
	assert(m_name != "");	
	assert(m_dimensions.x > 0.0f);
	assert(m_dimensions.y > 0.0f);
	assert(m_position.x > 0.5f*m_dimensions.x);
	assert(m_position.y > 0.5f*m_dimensions.y);
	
	m_rectangle.setOrigin(0.5f*m_dimensions);
	m_rectangle.setPosition(m_position);
	m_rectangle.setFillColor(m_color);
		
}

rectangle_entity::~rectangle_entity()
{
	
}

void show_rectent(sf::RenderWindow& window, const rectangle_entity& rectent)
{
    
   window.draw(rectent.m_rectangle);
    
}

struct rectangle_collection
{
	
	float m_value{100.0f};
    
    float m_norm_radius{20.0f};
    
    const float m_text_size{20.0f};
    
    const std::string m_rectangle_name{"Rectangle name"};
    
    const std::string m_circle_name{"Circle name"};
    
    const sf::Vector2f m_rectangle_position{0.0f, 0.0f};
    
    const sf::Vector2f m_rectangle_dimensions{200.0f, 100.0f};
    
    const float m_rectangle_mult{0.5f};
    
    const float m_text_mult{0.7f};
    
    const sf::Color m_color{255, 255, 255};
        
    const sf::Vector2f m_jump{0, -(m_rectangle_mult*m_rectangle_dimensions.y + m_text_mult*m_text_size)};  ////  m_mult*sqrt_value_tot_radius(m_value, m_norm_radius)
    
    const sf::Vector2f m_circle_position{m_rectangle_position - 0.5f*m_rectangle_dimensions +
	                              sf::Vector2f(0.25*m_rectangle_dimensions.y, 0.25*m_rectangle_dimensions.y)};
    
    rectangle_entity m_rectent{m_rectangle_name, m_rectangle_position, m_rectangle_dimensions};
    
    name_entity m_nament{m_rectangle_name, m_text_size, m_rectangle_position + m_jump, m_color};
    
    circle_collection m_circolle{m_value, m_norm_radius, m_text_size, m_circle_name, m_circle_position};
    
    rectangle_collection(const float value, const float norm_radius, const float text_size,
                            const std::string& rectangle_name, const std::string& circle_name,
                            const sf::Vector2f& rectangle_position, const sf::Vector2f& rectangle_dimensions);
                            
    ~rectangle_collection();
	
};


rectangle_collection::rectangle_collection(const float value, const float norm_radius, const float text_size,
                                           const std::string& rectangle_name, const std::string& circle_name,
                                           const sf::Vector2f& rectangle_position, const sf::Vector2f& rectangle_dimensions)
    :m_value(value), m_norm_radius(norm_radius), m_text_size(text_size), m_rectangle_name(rectangle_name),
    m_circle_name(circle_name), m_rectangle_position(rectangle_position), m_rectangle_dimensions(rectangle_dimensions),
    m_jump(0, -(m_rectangle_mult*m_rectangle_dimensions.y + m_text_mult*m_text_size)),
    m_circle_position(m_rectangle_position - 0.5f*m_rectangle_dimensions +
                      sf::Vector2f(0.25*m_rectangle_dimensions.y, 0.25*m_rectangle_dimensions.y)),
    m_rectent(m_rectangle_name, m_rectangle_position, m_rectangle_dimensions),
    m_nament(m_rectangle_name, m_text_size, m_rectangle_position + m_jump, m_color),
    m_circolle{m_value, m_norm_radius, m_text_size, m_circle_name, m_circle_position}
     
{
	
	assert(m_rectangle_name != "");
	assert(m_circle_name != "");
	assert(m_norm_radius > 0.0f);
	assert(m_text_size > 0.0f);	
	assert(m_rectangle_dimensions.x > 0.0f);
	assert(m_rectangle_dimensions.y > 0.0f);
	assert(m_rectangle_position.x > 0.5f*m_rectangle_dimensions.x);
	assert(m_rectangle_position.y > 0.5f*m_rectangle_dimensions.y);
	assert(m_rectangle_mult > 0.0f);
	assert(m_text_mult > 0.0f);
	assert(m_circle_position.x > 0.5f*m_rectangle_dimensions.x);
	assert(m_circle_position.y > 0.5f*m_rectangle_dimensions.y);
		
}

rectangle_collection::~rectangle_collection()
{
	
}

void show_rectcolle(sf::RenderWindow& window, const rectangle_collection& rectcolle)
{
    
   show_rectent(window, rectcolle.m_rectent);
   show_name_ent(window, rectcolle.m_nament);
   show_circolle(window, rectcolle.m_circolle);
    
}


float start_delta_end(const std::vector <float>& start_end, const int steps)
{
    
    assert(static_cast<int>(start_end.size()) == 2);
    
    assert(start_end[0] != start_end[1]);
    assert(steps > 0);

    return (start_end[1] - start_end[0])/steps;

}

float delta_divider(const float delta)
{
    
    return delta/100.0f;
    
}

void journey_maker(std::vector <float>& values, float& start_value)
{
    
    assert(static_cast<int>(values.size()) == 2);
    
    start_value = values[1];
    values[1] = values[0];
    values[0] = start_value;
    
}

void journey(std::vector <float>& values, float& current, float& delta)
{
    
    assert(static_cast<int>(values.size()) == 2);
    
    if (std::abs((current - values[1])) < std::abs(delta_divider(delta)))
    {
        
        journey_maker(values, current);        
        
        delta = -delta;
        
    }
    else
    {
                
        current += delta;
        
    }
    
    // std::cout << std::abs((current - values[1])) << ':' << std::abs(delta_divider(delta)) << '\n';
    
}

int main()
{
    
    const std::string program_name{"Top Down V0.10"};
    
    assert(program_name != "");
    
    const float window_x{1100.0f};
    const float window_y{700.0f};    
        
    assert(window_x > 0.0f);    
    assert(window_y > 0.0f);
    
    const sf::Vector2f window_sizes{window_x, window_y};
    
    const float norm_radius{0.1f*window_y};
    
    const int delaz{25};    
    assert(delaz > 0);
    
    const std::chrono::milliseconds delay(delaz);
    
    const sf::Color white{sf::Color(255, 255, 255)};    
    const sf::Color black{sf::Color(0, 0, 0)};    
    const sf::Color orange{sf::Color(255, 127, 0)};    
    const sf::Color purple{sf::Color(127, 0, 255)};    
    const sf::Color cyan{sf::Color(127, 255, 255)};
    const sf::Color red{sf::Color(255, 0, 0)};
    const sf::Color yellow{sf::Color(255, 255, 0)};
    const sf::Color green{sf::Color(0, 255, 0)};
    const sf::Color blue{sf::Color(0, 0, 255)};    
    
    const std::string nament_name{"Agegta"};
    
    const std::string nament_name_2{"Chiaki\nKurihara"};
    
    const std::string nament_name_3{"Tetsuko\nKoku"};
    
    std::vector <float> attain_values{-1000.0f, 1000.0f};
    
    const int steps{200};
    
    float current_value{attain_values[0]};
    float delta_value{start_delta_end(attain_values, steps)};
    
    // std::cout << delta_value << ':' << delta_divider(delta_value) << '\n';
    
    const float nament_size{15.0f};
    const float valuent_size{15.0f};
    
    const float nament_value{10000.0f};
    
    ////////////////////////////////////////
    
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
    
    const sf::Vector2f nament_posit{0.25f*window_sizes};    
    name_entity nament{nament_name, nament_size, nament_posit, yellow};
    
    const sf::Vector2f valuent_posit{0.75f*window_sizes};    
    value_entity valuent{current_value, valuent_size, valuent_posit, cyan};
    
    const sf::Vector2f circle_posit{0.5f*window_sizes};    
    circle_entity circlent{current_value, norm_radius, circle_posit};
    
    const sf::Vector2f circolle_posit{0.25f*window_sizes.x, 0.5f*window_sizes.y};
    circle_collection circolle{nament_value, norm_radius, valuent_size, nament_name, circolle_posit};
    
    const sf::Vector2f rectent_posit_2{0.25f*window_sizes.x, 0.75f*window_sizes.y};
    const sf::Vector2f rectent_dimens{0.4f*window_sizes};
    rectangle_collection rectcolle{attain_values[0], norm_radius, valuent_size,
	                               nament_name_2, nament_name_3, rectent_posit_2, rectent_dimens};
                
    while (window.isOpen())
    {

        sf::Event event;
        
        window.clear(black);
        
                
        show_circle_ent(window, circlent);
        
        show_name_ent(window, nament);
        
        show_value_ent(window, valuent);
        
        show_circolle(window, circolle);
        
        show_rectcolle(window, rectcolle);
        
        window.display();
        
        
        journey(attain_values, current_value, delta_value);
        
        revalue_circlent(circlent, current_value);
        
        revalue_valuent(valuent, current_value);
        
        
        std::this_thread::sleep_for(delay);
                    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            
            window.close();
                    
            return 1;
                    
        }    
        
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
            {
                
                window.close();
                
                return 2;
                
            }
        
        }
            

    }
    
    return 0;

}
