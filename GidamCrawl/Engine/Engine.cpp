#include "Engine.h"
#include <Windows.h>
#include <conio.h>
#include <stdint.h>
#include <iostream>
#include <cassert>

namespace Gidam
{
	// 전역 객체 초기화
	Engine* Engine::instance = nullptr;

	Engine::Engine()
	{
		assert(!instance);
		instance = this;
	}

	Engine::~Engine()
	{
		instance = this;
	}
	
	void Engine::Run()
	{
		// 윈도우가 제공하는 고해상도 타이머(하드웨어 타이머)

		// QueryPerformanceFrequency: 타이머의 해상도
		// e.g. Millisecond (1/000) 해상도 = 1000
		LARGE_INTEGER frquency;
		QueryPerformanceFrequency(&frquency);
		
		// 현재 시간 확인
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);

		// 프레임 시간 계산을 위한 변수
		int64_t currentTime = counter.QuadPart;
		int64_t previousTime = currentTime;

		// 프레임 고정
		float oneFrameTime = 1.0f / settings.framerate;

		while (!isQuit)
		{
			// 입력 처리
			ProcessInput();

			// 현재 시간 측정(확인)
			QueryPerformanceCounter(&counter);
			int64_t currentTime = counter.QuadPart;

			// 프레임 시간 계산
			float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frquency.QuadPart);

			// 고정 프레임 처리
			if (deltaTime >= oneFrameTime)
			{
				// 레벨 초기화 이벤트 함수
				OnInitialized();

				// 레벨의 액터 초기화 이벤트 함수
				BeginPlay();

				// 레벨의 액터 초기화 함수
				Tick(deltaTime);

				// 업데이트된 결과를 화면에 그리는 함수
				Draw();

				// 처리된 입ㅈ력을 이전 프레임 입력으로 저장
				SavePreviousInputStates();

				// 다음 프레임을 위해 previousTime을 currentTime으로 갱신
				previousTime = currentTime;
			}
		}

		// 정리
		Shutdown();
	}
	
	void Engine::Quit()
	{
		// 종료 플래그 설정
		isQuit = true;
	}

	Engine& Engine::Get()
	{
		assert(instance);

		return *instance;
	}
	
	void Engine::ProcessInput()
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 27)		// ESC = ASCII 27
			{
				std::cout << "ESC pressed. Exiting...\n";
				isQuit = true;
			}
		}
	}
	
	void Engine::OnInitialized()
	{
	}
	
	void Engine::BeginPlay()
	{
	}

	void Engine::Draw()
	{
	}
	
	void Engine::Tick(float deltaTime)
	{
		std::cout
			<< "DeltaTime: " << deltaTime
			<< " | FPS: " << (1.0f / deltaTime)
			<< "\n";
	}
	
	void Engine::SavePreviousInputStates()
	{
	}
	
	void Engine::Shutdown()
	{
	}
}