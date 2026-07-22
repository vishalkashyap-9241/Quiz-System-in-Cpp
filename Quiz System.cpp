#include <iostream>
#include <string>
using namespace std;

const int TOTAL_QUESTIONS = 10;
class Question
{
public:
    string question;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;

    void setQuestion(string q, string a, string b, string c, string d, char ans)
    {
        question = q;
        optionA = a;
        optionB = b;
        optionC = c;
        optionD = d;
        correctAnswer = ans;
    }
    void displayQuestion(int number)
    {
        cout << "\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n";
        cout << "Question " << number << endl;
        cout << question << endl;
        cout << "A. " << optionA << endl;
        cout << "B. " << optionB << endl;
        cout << "C. " << optionC << endl;
        cout << "D. " << optionD << endl;
        cout << "Enter Answer (A/B/C/D): ";
    }
    bool checkAnswer(char answer)
    {
        if(answer >= 'a' && answer <= 'z')
            answer -= 32;

        return answer == correctAnswer;
    }
};

class Student
{
public:
    int score;

    Student()
    {
        score = 0;
    }
};

class Result
{
public:
    void display(int score)
    {
        float percentage = (score * 100.0) / TOTAL_QUESTIONS;

        cout << "\n====================================";
        cout << "\n           QUIZ RESULT";
        cout << "\n====================================";
        cout << "\nCorrect Answers : " << score;
        cout << "\nWrong Answers   : " << TOTAL_QUESTIONS - score;
        cout << "\nPercentage      : " << percentage << "%";

        cout << "\nGrade           : ";

        if(percentage >= 90)
            cout << "A+";
        else if(percentage >= 80)
            cout << "A";
        else if(percentage >= 70)
            cout << "B";
        else if(percentage >= 60)
            cout << "C";
        else
            cout << "F";

        if(percentage >= 40)
            cout << "\nStatus          : PASS";
        else
            cout << "\nStatus          : FAIL";

        cout << "\n====================================\n";
    }
};

class Quiz
{
private:
    Question questions[TOTAL_QUESTIONS];

public:
    Quiz()
    {
        loadQuestions();
    }

    void loadQuestions()
    {
        questions[0].setQuestion(
            "Who is known as the Father of Computer?",
            "Charles Babbage",
            "Bill Gates",
            "Steve Jobs",
            "Dennis Ritchie",
            'A');

        questions[1].setQuestion(
            "Which language is used in this project?",
            "Java",
            "Python",
            "C++",
            "PHP",
            'C');

        questions[2].setQuestion(
            "Which symbol ends a C++ statement?",
            ".",
            ";",
            ":",
            ",",
            'B');

        questions[3].setQuestion(
            "Which loop executes at least once?",
            "for",
            "while",
            "do while",
            "foreach",
            'C');

        questions[4].setQuestion(
            "How many bits are in one byte?",
            "4",
            "8",
            "16",
            "32",
            'B');
            questions[5].setQuestion(
            "Which header file is used for input and output in C++?",
            "stdio.h",
            "iostream",
            "math.h",
            "conio.h",
            'B');

        questions[6].setQuestion(
            "Which operator is used to compare two values?",
            "=",
            "==",
            "!=",
            ">",
            'B');

        questions[7].setQuestion(
            "Which data type stores decimal values?",
            "int",
            "char",
            "float",
            "bool",
            'C');

        questions[8].setQuestion(
            "Which keyword is used to define a class in C++?",
            "object",
            "class",
            "struct",
            "define",
            'B');

        questions[9].setQuestion(
            "Who developed C++?",
            "James Gosling",
            "Dennis Ritchie",
            "Bjarne Stroustrup",
            "Guido van Rossum",
            'C');
    }

    void startQuiz(Student &student)
    {
        char answer;
        student.score = 0;

        cout << "\n========================================";
        cout << "\n        ONLINE QUIZ STARTED";
        cout << "\n========================================";

        for(int i = 0; i < TOTAL_QUESTIONS; i++)
        {
            questions[i].displayQuestion(i + 1);

            cin >> answer;

            if(questions[i].checkAnswer(answer))
            {
                cout << "Correct Answer!\n";
                student.score++;
            }
            else
            {
                cout << "Wrong Answer!\n";
                cout << "Correct Answer : "
                     << questions[i].correctAnswer << endl;
            }
        }
    }
};
int main()
{
    Student student;
    Quiz quiz;
    Result result;

    cout << "=========================================\n";
    cout << "      ONLINE QUIZ SYSTEM \n";
    cout << "=========================================\n";
    cout << "Total Questions : " << TOTAL_QUESTIONS << endl;
    cout << "Each Correct Answer = 1 Mark\n";
    cout << "Press Enter to Start...";
    cin.ignore();
    cin.get();

    quiz.startQuiz(student);

    result.display(student.score);

    cout << "\nThank You For Using Online Quiz System.\n";
    cout << "Press Enter to Exit...";
    cin.ignore();
    cin.get();

    return 0;
}

        
