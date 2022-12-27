#pragma once
#include "Core.h"
#include "Renderer.h"


class Runtime {

public:

	Runtime(Renderer* glRenderer);
	virtual ~Runtime() = default;

	Renderer* renderer;
	void run();
};