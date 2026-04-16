#pragma once

namespace Gidam
{
	class Engine
	{
	public:
		Engine();
		virtual ~Engine();

		// Game Loop execution function
		void Run();

		// Engine quit function
		void Quit();

	protected:
		// Input processing function
		void ProcessInput();

		// Initialization function
		void OnInitialized();

		// Start function
		void BeginPlay();

		// Render function
		void Draw();

		// Update function
		void Tick(float deltaTime);

		// Save the previous function
		void SavePreviousInputStates();

		// Resource release function
		void Shutdown();
	};
}

