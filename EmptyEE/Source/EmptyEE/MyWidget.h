// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CanvasPanel.h"
#include "Image.h"
#include "Button.h"
#include "TextBlock.h"
#include "Text.h"
#include "MyWidget.generated.h"

UCLASS()
class EMPTYEE_API UMyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void OnBtnLanguageA();
	UFUNCTION()
	void OnBtnLanguageB();
	UFUNCTION()
	void OnBtnMakePatch();
	UFUNCTION()
	void OnBtnApplyPatch();

private:
	UPROPERTY(Meta = (BindWidget))
	UButton *Btn_LanguageA;

	UPROPERTY(Meta = (BindWidget))
	UButton* Btn_LanguageB;

	UPROPERTY(Meta = (BindWidget))
	UButton* Btn_MakePatch;

	UPROPERTY(Meta = (BindWidget))
	UButton* Btn_ApplyPatch;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* Text_Hero;
		
	int m_nPatchIndex;
};
