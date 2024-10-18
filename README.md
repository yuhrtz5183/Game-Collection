# C++ Games Collection

Welcome to the C++ Games Collection repository! This repository contains classic games implemented in C++ including Blackjack, Craps, Hangman, and Tic-Tac-Toe. The games can be played in a simple terminal/console environment.

## Table of Contents
- [Introduction](#introduction)
- [Games Included](#games-included)
  - [Blackjack](#blackjack)
  - [Craps](#craps)
  - [Hangman](#hangman)
  - [Tic-Tac-Toe](#tic-tac-toe)
- [Setup and Installation](#setup-and-installation)
- [How to Play](#how-to-play)


## Introduction
This repository features the implementation of several popular games in C++. Each game can be played directly from the terminal, and all are designed for single-player interaction against either a computer opponent (in games like Blackjack and Tic-Tac-Toe) or for solo play (like Hangman and Craps).

## Games Included

### Blackjack
**Description**: A card game where the player competes against the computer. The goal is to have a hand total closer to 21 than the computer without going over.

- **Rules**: 
  - The player is dealt two cards.
  - The player can choose to either "hit" (get another card) or "stand" (keep their current hand).
  - If the player's hand exceeds 21, they lose.
  - The computer must continue hitting until it reaches at least 17.

### Craps
**Description**: A dice game where players bet on the outcome of a roll or series of rolls.

- **Rules**:
  - On the first roll, a 7 or 11 wins the game, while a 2, 3, or 12 results in a loss.
  - Any other number rolled becomes the "point," and the player must keep rolling the dice until they either match the point (win) or roll a 7 (lose).

### Hangman
**Description**: A word-guessing game where the player tries to guess a word by suggesting letters within a limited number of attempts.

- **Rules**:
  - The player has a set number of guesses to find the hidden word.
  - Each incorrect guess adds a part to the hangman figure.
  - The player wins by guessing the word before the figure is fully drawn.

### Tic-Tac-Toe
**Description**: A simple two-player game played on a 3x3 grid. The player competes against the computer, aiming to get three of their marks in a row.

- **Rules**:
  - The player and the computer take turns placing their mark (X or O) on the board.
  - The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins.
  - If the board is filled and neither player has three in a row, the game ends in a tie.
