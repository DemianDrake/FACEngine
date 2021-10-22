#pragma once

#include "Platform/Win32/IApplication.h"

class Application : public IApplication {

	// Application

public:
	/* Application Constructor */
	Application();

	/* Application Destructor */
	~Application();

public:
	/* Called to Initialize the Application */
	VOID Initialize();

	/* Game Loop - Called on a loop while the Application is running */
	VOID Update();
};