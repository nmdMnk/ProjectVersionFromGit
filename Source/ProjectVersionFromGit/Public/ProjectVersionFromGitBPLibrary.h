// Copyright 2025 Andrew Bindraw. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "ProjectVersionGitSettings.h"
#include "ProjectVersionFromGitBPLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectVersionFromGitBPLibrary, Log, All);

DECLARE_DYNAMIC_DELEGATE(FParseVersionDelegate);

UCLASS()
class PROJECTVERSIONFROMGIT_API UProjectVersionFromGitBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	virtual void PostInitProperties() override;

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static FText GetProjectVersion();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static int32 GetProjectVersionMajor();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static int32 GetProjectVersionMinor();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static int32 GetProjectVersionPatch();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static int32 GetProjectVersionBuild();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static FText GetProjectVersionBranchName();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static FText GetProjectVersionCommitHash();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static FText GetProjectVersionDateTimeBuild();

	UFUNCTION(BlueprintPure, Category = "ProjectVersionFromGit")
	static FText GetProjectVersionFormatAll();

	UFUNCTION(BlueprintCallable, Category = "ProjectVersionFromGit")
	static void GetProjectVersionInfo(FParseVersionDelegate OnCompleted);

	static bool ExecProcess(const TCHAR* URL, const TCHAR* Params, int32* OutReturnCode, FString* OutStdOut, FString* OutStdErr, const TCHAR* OptionalWorkingDirectory);

private:
	static FText ProjectVersion;
	static FText ProjectVersionFormatAll;
	static FText CommitHash;
	static FText BranchName;
	static FText DateTimeBuild;
	static int32 Major;
	static int32 Minor;
	static int32 Patch;
	static int32 Build;

	static FString SectionName;
	static FString VersionFileIni;

	static FString GitStdOutput;
};
