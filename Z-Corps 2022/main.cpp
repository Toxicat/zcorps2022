#include "SkullEngine\Core.hpp"
#include "SkullEngine\Window.hpp"
#include "SkullEngine\Assets.hpp"
#include "Screens.hpp"

int     main()
{
    SkullEngine::Core GameCore;
    SkullEngine::Asset::AssetManager &AssetManager = GameCore.Assets();

    SkullEngine::Asset::Texture splash_background_texture("splash_background_texture", "Assets/img/splash.jpg");
    AssetManager.LoadAsset(splash_background_texture);
    SkullEngine::Asset::SimpleSprite splash_background_image("splash_background_image", dynamic_cast<SkullEngine::Asset::Texture &>(AssetManager.GetAsset("splash_background_texture")));
    AssetManager.LoadAsset(splash_background_image);
    
    SkullEngine::Window::Window splash_window(SkullEngine::WindowType::SPLASHSCREEN, 1004, 357, "Splash screen", AssetManager);
    SkullEngine::Window::Scene splash_scene("Splash Screen");

    SplashScreenBackground  splash_screen(splash_window.Manager(), AssetManager, splash_window);

    splash_scene.AddScreen(splash_screen);
    splash_window.FirstScene(splash_scene);

    GameCore.AddWindow(splash_window);
    GameCore.Run();
    
    system("PAUSE");
    return 0;
}
