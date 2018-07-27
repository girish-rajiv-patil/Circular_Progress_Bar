#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <ui/CocosGUI.h>
#include "Cirular_Progress_bar.h"
USING_NS_CC;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    
    log("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    float size = 200;
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }



	Cirular_Progress_bar game;
	
	//game.progressBar_LR(this);
	game.circularBar_RL(this);
      
	return true;
    }


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
