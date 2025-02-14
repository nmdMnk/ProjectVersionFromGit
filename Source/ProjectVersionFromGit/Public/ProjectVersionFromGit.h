// Copyright 2024 Andrew Bindraw. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(ProjectVersionFromGit, Log, All);
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ProjectVersionGitSettings.h"
#endif

class FProjectVersionFromGitModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
