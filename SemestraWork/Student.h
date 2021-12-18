#pragma once
#include "Utils.h"
#include "List.h"
// ====================================================================================================
// class Student
// ====================================================================================================


//nahradit metody metodami listu


/// Total number of planned tasks.
const int PLANNED_TASK_COUNT = 5;

/// Max score a student can received from a single task.
const int MAX_SCORE = 10;

/// Represents a student of a programming course.
///
/// Allows to compute basic statistics of scores the student received from submitted tasks and decide
/// whether the student passed the course.
class Student
{
private:
	/// Full name of this student.
	std::string mName;

	List mScoresList;

	/// Buffer for storing scores this student receives from submitted tasks.
	//int mScores[PLANNED_TASK_COUNT]; //zahodit a nahradit listem

	/// Number of scores this student already received.
	//int mScoreCount = 0; //zahodit a nahradit listem

public:
	/// Constructor initializing the student's name.
	///
	/// \note It prints a construction message to demonstrate that the constructor was called.
	Student(std::string name) {
		mName = name;
		printConstructionMessage();
	}

	/// Constructor initializing the student's name and adding his first score.
	///
	/// \note It prints a construction message to demonstrate that the constructor was called.
	Student(std::string name, int firstScore) {
		mName = name;
		addScore(firstScore);
		printConstructionMessage();
	}

	/// Destructor deallocating the memory whenever this instance ceases to exist.
	///
	/// \note It prints a destruction message to demonstrate that the destructor was called.
	~Student() {
		printDestructionMessage();
	}

	/// Adds the received score to this student record. 
	void addScore(int score) {
		if (mScoreCount >= PLANNED_TASK_COUNT) {
			printWarning("Student::addScore(): All planned tasks already graded.");
		}
		else if (score < 0 || score > MAX_SCORE) {
			printWarning("Student::addScore(): Received an invalid score value.");
		}
		else {
			mScores[mScoreCount] = score;
			mScoreCount++;
		}
	}

	/// Returns the highest score this student received.
	int getHighestScore() {
		if (mScoreCount <= 0) {
			printWarning("Student::getHighestScore(): No scores available.");
			return 0;
		}
		int highestScore = mScores[0];
		for (int i = 1; i < mScoreCount; i++) {
			if (mScores[i] > highestScore) { //get value [i] nahradit
				highestScore = mScores[i];
			}
		}
		return highestScore;
	}

	/// Returns sum of all scores this student received.
	int getTotalScore() {
		int totalScore = 0;
		for (int i = 0; i < mScoreCount; i++) {
			totalScore += mScores[i];
		}
		return totalScore;
	}

	/// Returns the average score this student received.
	double getAverageScore() {
		if (mScoreCount <= 0) {
			printWarning("Student::getAverageScore(): No scores available.");
			return 0.0;
		}
		return double(getTotalScore()) / mScoreCount;
	}

	/// Returns whether this student passed the course.
	bool hasPassed() {
		const int SUFFICIENT_SCORE_COUNT = 3;
		if (mScoreCount >= SUFFICIENT_SCORE_COUNT) {
			const double SUFFICIENT_AVERAGE = double(MAX_SCORE) / 2;
			if (getAverageScore() >= SUFFICIENT_AVERAGE) {
				return true;
			}
		}
		return false;
	}

	/// Prints a report containing this student's study results.
	void printReport() {
		skipLine();

		std::cout << ">>>>>" << " Student Report " << "<<<<<" << std::endl;
		std::cout << "Name: " << mName << std::endl;

		printReceivedScores();
		printScoreStats();
		printFinalResult();

		std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;

		skipLine();
	}

private:
	/// Prints a construction message.
	void printConstructionMessage() {
		printSeparator('+');
		std::cout << "Student::Constructor: " << mName << " was born." << std::endl;
		printSeparator('+');
	}

	/// Prints a destruction message.
	void printDestructionMessage() {
		printSeparator('-');
		std::cout << "Student::Destructor: " << mName << " was killed." << std::endl;
		printSeparator('-');
	}

	/// Prints all scores this student has already received.
	void printReceivedScores() {
		std::cout << "Received scores: ";
		if (mScoreCount <= 0) {
			std::cout << "<empty>";
		}
		else {
			for (int i = 0; i < mScoreCount; i++) {
				std::cout << mScores[i] << " ";
			}
		}
		std::cout << std::endl;
	}

	/// Prints stats of this student's scores.
	void printScoreStats() {
		std::cout << "Score stats:" << std::endl;

		const int totalScore = getTotalScore();
		printBulletPoint("Total:", totalScore);

		const int averageScore = getAverageScore();
		printBulletPoint("Average:", averageScore);

		const int highestScore = getHighestScore();
		printBulletPoint("Highest:", highestScore);
	}

	/// Prints whether this student passed the course.
	void printFinalResult() {
		std::cout << "Final result: ";
		if (hasPassed()) {
			std::cout << "Passed!" << std::endl;
		}
		else {
			std::cout << "Failed!" << std::endl;
		}
	}
};
