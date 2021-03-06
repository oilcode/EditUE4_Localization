// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWidget.h"
#include "TextLocalizationResource.h"
#include "TextLocalizationManager.h"

bool UMyWidget::Initialize()
{
	if (Super::Initialize() == false)
	{
		return false;
	}

	Btn_LanguageA->OnClicked.__Internal_AddDynamic(this, &UMyWidget::OnBtnLanguageA, FName("OnBtnLanguageA"));
	Btn_LanguageB->OnClicked.__Internal_AddDynamic(this, &UMyWidget::OnBtnLanguageB, FName("OnBtnLanguageB"));
	Btn_MakePatch->OnClicked.__Internal_AddDynamic(this, &UMyWidget::OnBtnMakePatch, FName("OnBtnMakePatch"));
	Btn_ApplyPatch->OnClicked.__Internal_AddDynamic(this, &UMyWidget::OnBtnApplyPatch, FName("OnBtnApplyPatch"));

	Text_Hero->SetText(NSLOCTEXT("MyTestCode", "Key_HP", "生命"));
	
	m_nPatchIndex = 0;
	return true;
}

void UMyWidget::OnBtnLanguageA()
{
	FInternationalization::Get().SetCurrentCulture(TEXT("zh-Hans-CN"));
}

void UMyWidget::OnBtnLanguageB()
{
	FInternationalization::Get().SetCurrentCulture(TEXT("en"));
}

void UMyWidget::OnBtnMakePatch()
{
	++m_nPatchIndex;
	FString GamePath = FPaths::GetGameLocalizationPaths()[0];

	FString Namespace = TEXT("MyTestCode");
	FString Key = TEXT("Key_HP");
	FString SourceString = TEXT("生命");
	int32 Priority = 0;
	FString LocResID = TEXT("");

	FString LocalizedString_en = FString::Printf(TEXT("HP_P%d"), m_nPatchIndex);
	FString TargetFile_en = FString::Printf(TEXT("%s/en/P%d_Game.locres"), *GamePath, m_nPatchIndex);
	FTextLocalizationResource MyLocalizedResource_en;
	MyLocalizedResource_en.AddEntry(Namespace, Key, SourceString, LocalizedString_en, Priority, LocResID);
	MyLocalizedResource_en.SaveToFile(TargetFile_en);

	FString LocalizedString_cn = FString::Printf(TEXT("生命_P%d"), m_nPatchIndex);
	FString TargetFile_cn = FString::Printf(TEXT("%s/zh-Hans-CN/P%d_Game.locres"), *GamePath, m_nPatchIndex);
	FTextLocalizationResource MyLocalizedResource_cn;
	MyLocalizedResource_cn.AddEntry(Namespace, Key, SourceString, LocalizedString_cn, Priority, LocResID);
	MyLocalizedResource_cn.SaveToFile(TargetFile_cn);
}

void UMyWidget::OnBtnApplyPatch()
{
	FTextLocalizationManager::Get().MyApplyCulturePatch();
}

