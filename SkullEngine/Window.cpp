#include "Window.hpp"

namespace SkullEngine
{
    namespace Window
    {
        Window::Window(WindowType t, uint w, uint h, const std::string &n, Scene &fs, Asset::AssetManager &a) :
            _type(t),
            _width(w),
            _height(h),
            _name(new std::string(n)),
            _assets(a),
            _exit(false),
            _current(&fs),
            _scm(new ScreenManager::ScreenManager(*this))
        {
        }

        void    Window::AddScene(Scene &s)
        {
            _scenes[s.Name()] = &s;
        }
        void    Window::LoadScene(const std::string &name)
        {
            scene_map::iterator it = _scenes.find(name);

            if (it != _scenes.end())
                LoadScene(*(it->second));
        }
        void    Window::LoadScene(Scene &s)
        {
        }
        const sf::RenderWindow  &Window::Render()
        {
            return *_render;
        }
        void    Window::Start()
        {
            if (_type == WindowType::SPLASHSCREEN)
                _render = new sf::RenderWindow(sf::VideoMode(_width, _height), "", sf::Style::None);
            else
                _render = new sf::RenderWindow(sf::VideoMode(_width, _height), *_name, sf::Style::Close | sf::Style::Titlebar);
            LoadScene(*_current);
        }
        void    Window::Exit() const
        {
            _render->close();
        }
        void    Window::Run() const
        {
            _scm->Run();
        }
    }
}