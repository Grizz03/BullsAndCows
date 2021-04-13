// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{

    /* 
    if game is not over do ClearScreen() and InitGame() 
    else Checking PlayerGuess 
    */

    if (bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else // Checking PlayerGuess
    {
        ProcessGuess(Input);
    }
}

// Check player guess

// Check right number of char
// Prompt to guess again
// Check if isogram
// Prompt to guess again

// Remove Life

// Are lives > 0?
// If Yes GuessAgain
// Show lives left
// If No Show GameOver and HiddenWord
// Prompt to Play Again, press enter to play again?
// Check User Input
// Play Again or Quit Game

void UBullCowCartridge::InitGame()
{
    PrintLine(TEXT("Welcome to Bull Cow!"));
    HiddenWord = TEXT("cakes"); // Set the HiddenWord
    Lives = HiddenWord.Len();   // Set Lives
    bGameOver = false;
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("\nYou Won!"));
        EndGame();
    }
    else
    {
        --Lives;
        if (Lives > 0)
        {
            PrintLine(TEXT("You have %i lives remaining."), Lives);
            if (Guess.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The word is %i characters long."), HiddenWord.Len());
            }
        }
        else
        {
            PrintLine(TEXT("You have no lives left!"));
            PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
            EndGame();
        }
    }
}