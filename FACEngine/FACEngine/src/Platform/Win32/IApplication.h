#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class FACENGINE_API IApplication {

	// Application

public:
	/* Application Constructor */
	IApplication();

	/* Application Destructor */
	virtual ~IApplication() {};

public:
	/* Called to Initialize the Application */
	virtual VOID Initialize() {};

	/* Game Loop - Called on a loop while the Application is running */
	virtual VOID Update() {};
};

IApplication* EntryApplication();