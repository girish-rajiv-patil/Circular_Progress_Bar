#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Cirular_Progress_bar.h"
#include <ui/CocosGUI.h>
USING_NS_CC;


void Cirular_Progress_bar::progressBar_LR(Node *node)
{
	    //progressBar left to right progress show"); 
	    cocos2d::ui::LoadingBar *loadingbar = cocos2d::ui::LoadingBar::create("girish.png");
	    if (loadingbar != nullptr)
	    {
		loadingbar->setPosition(Vec2(600,500));
		
		loadingbar->setPercent(0);
		node->addChild(loadingbar);
		node->schedule([=](float delta){
		float percent = loadingbar->getPercent();
		percent++;
		loadingbar->setPercent(percent);
		if (percent>=100.0f) {
		node->unschedule("updateLoadingBar");
		}
		}, 0.1f, "updateLoadingBar");
	    }
	    else 
	      log("null");

	  
}


//CircularBar clockwise progress show"); 
void Cirular_Progress_bar::circularBar_RL(Node* node)
{

	      ProgressTimer* TimerForElement  = ProgressTimer::create(Sprite::create("circularBar.png"));
	      //ProgressTimer* TimerForElement  = ProgressTimer::create(load);  	//load can be sprite you can take from plist or local or xml
	      TimerForElement->setType(ProgressTimer::Type::RADIAL);
	      TimerForElement->setPercentage(0);
	      TimerForElement->setBarChangeRate(Vec2(0.5,0));
	      TimerForElement->setPosition( Vec2(200,200) );
	      node->addChild(TimerForElement);

	      
	      node->schedule([=](float delta)
	      {
		    float percent = TimerForElement->getPercentage();
		    percent++;
		    TimerForElement->setPercentage(percent);
		    TimerForElement->runAction(RotateTo::create(0.1,10.0f));
	  
		    if (percent>=100.0f)
		    {
			  node->unschedule("updateLoadingBar");
		    }
	      }, 1.0f, "updateLoadingBar");
		

}


