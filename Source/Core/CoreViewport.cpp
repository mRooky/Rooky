/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */


#include "GHICommandList.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIImage.h"
#include "CoreViewport.h"
#include "CoreSystem.h"
#include "CoreThread.h"
#include "CoreScene.h"
#include "CoreCamera.h"

#include <cassert>

namespace Core
{

Viewport::Viewport(Scene* scene):
		mParent(scene)
{
	assert(mParent != nullptr);
}

Viewport::~Viewport(void)
{
	delete mCamera;
	mCamera = nullptr;
	delete mThread;
	mThread = nullptr;
}

void Viewport::Create(const Math::Rect2Di& rect)
{
	mViewport = rect;
	mCamera = new Camera;
	assert(rect.IsValid());
}

void Viewport::CreateThread(uint32_t count)
{
	System* system = mParent->GetSystem();
	mThread = new Core::Thread(system);
	mThread->Create(count);
}

void Viewport::Draw(void)
{
	assert(mThread != nullptr);

	Math::Rect2Di area = mViewport.GetExtent();
	Math::Rect2Di scissor = area;

	GHI::CommandList* command = mThread->GetCommandList(0);
	command->Begin();
	command->SetScissor(0, 1, &scissor);
	command->SetViewport(0, 1, &mViewport);
	DrawScene();
	command->End();
}

void Viewport::DrawScene(void)
{

}

} /* namespace Core */
