// Copyright 2025 Andrew Bindraw. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/ConfigCacheIni.h"
#include "ProjectVersionGitSettings.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectVersionGitSettings, Log, All);

DECLARE_MULTICAST_DELEGATE(FPostInitPropertiesDelegate);

#if WITH_EDITOR
DECLARE_MULTICAST_DELEGATE(FPostEditChangePropertyDelegate);
#endif

UCLASS(Config = EditorPerProjectUserSettings)
class PROJECTVERSIONFROMGIT_API UProjectVersionGitSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UProjectVersionGitSettings(const FObjectInitializer& ObjectInitializer);

    virtual void PostInitProperties() override;
	static FPostInitPropertiesDelegate OnPostInitPropertiesCompleted;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	static FPostEditChangePropertyDelegate OnPostEditChangePropertyCompleted;
#endif
 
	UPROPERTY(Config, EditAnywhere, Category = "Settings", DisplayName = "Path to git binary file")
	FString GitBinPath;

	// If true, the commit hash will be prefixed with "unclean-"
	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	bool bUseUnCleanCommitHash;
};
