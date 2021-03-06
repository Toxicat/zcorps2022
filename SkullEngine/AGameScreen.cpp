#include <SFML\Window\Event.hpp>

#include "SkullEngine\AGameScreen.hpp"
#include "SkullEngine\Exception.hpp"
#include "SkullEngine\Window.hpp"
#include "SkullEngine\Core.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        AGameScreen::AGameScreen(ScreenManager::ScreenManager &sm, Asset::AssetManager &am, Window::Window &w, Core &c, const std::string &n) :
            _active(false),
            _popup(false),
            _layer(100),
            _name(new std::string(n)),
            _manager(sm),
            _assets(am),
            _win(w),
            _core(c)
        {
        }

        void AGameScreen::Event()
        {
            sf::Event   event;
            while (_win.Render().pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    _win.Exit();
                    _manager.Break();
                }
            }
        }

        bool AGameScreen::IsActive() const
        {
            return _active;
        }
        bool AGameScreen::IsPopup() const
        {
            return _popup;
        }
        ushort AGameScreen::Layer() const
        {
            return _layer;
        }
        const std::string &AGameScreen::Name() const
        {
            return *_name;
        }

        void AGameScreen::On()
        {
            try
            {
                if (IsActive())
                    throw Exception("Screen [" + Name() + "] is already active");
                _active = true;
            } catch (Exception ex)
            {
                _core.cout("EXCEPTION : " + ex.msg());
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::Off()
        {
            try
            {
                if (!IsActive())
                    throw Exception("Screen [" + Name() + "] is already unactive");
                _active = false;
            } catch (Exception ex)
            {
                _core.cout("EXCEPTION : " + ex.msg());
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::PopUp()
        {
            try
            {
                if (IsPopup())
                    throw Exception("Screen [" + Name() + "] is already on top");
                _popup = true;
            } catch (Exception ex)
            {
                _core.cout("EXCEPTION : " + ex.msg());
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::PopDown()
        {
            try
            {
                if (!IsPopup())
                    throw Exception("Screen [" + Name() + "] is already on background");
                _popup = false;
            } catch (Exception ex)
            {
                _core.cout("EXCEPTION : " + ex.msg());
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::LayerUp()
        {
            ++_layer;
        }
        void AGameScreen::LayerDown()
        {
            --_layer;
        }
    }
}
