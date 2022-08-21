#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
	virtual void UnExecute() = 0;
protected:
	Command() {}
};

// Receiver
class Calculator {
private:
	int current_value = 0;
public:
	Calculator() {
		current_value = 0;
	}

	void Action(char _operator, int operand) {
		switch (_operator) {
			case '+': current_value += operand; break;
			case '-': current_value -= operand; break;
			case '*': current_value *= operand; break;
			case '/': current_value /= operand; break;
		}
		cout << "Current value " << current_value << " (following " << _operator << " " << operand << ")" << endl;
	}
};

class CalculatorCommand : public Command{
public:
	CalculatorCommand(Calculator* c, char op, int operand) : calculator(c) {
		this->_operator = op;
		this->_operand = operand;
	}

	~CalculatorCommand()
	{
		if (calculator)
		{
			delete calculator;
		}
	}

	void Execute() {
		calculator->Action(_operator, _operand);
	}
	void UnExecute() {
		calculator->Action(Undo(_operator), _operand);
	}
	// ...
	char Undo(char _operator) {
		switch (_operator) {
		case '+': return '-';
		case '-': return '+';
		case '*': return '/';
		case '/': return '*';
		default:  return ' ';
		}
	}

private:
	Calculator* calculator;
	char _operator;
	int _operand;
	// ...
};

//Invoker
class User {
private:
	int current = 0;
	vector<Command*> _commands;
public:
	void Redo(int levels) {
		cout << "\n---- Redo " << levels << " levels " << endl;
		// Perform redo operations
		for (int i = 0; i < levels; i++) {
			if (current < _commands.size()) {
				Command* command = _commands.at(current++);
				command->Execute();
			}
		}
	}

	void Undo(int levels) {
		cout << "\n---- Undo " << levels << " levels " << endl;
		// Perform undo operations
		for (int i = 0; i < levels; i++) {
			if (current > 0) {
				Command* command = _commands.at(--current);
				command->UnExecute();
			}
		}
	}
	void Compute(Command *command) {
		command->Execute();
		// Add command to undo list
		_commands.push_back(command);
		current++;
	}
};

int main()
{
	// Create user and let her compute
	Command *command;
	User *user = new User();
	Calculator *calculator = new Calculator();

	command = new CalculatorCommand(calculator, '+', 100);
	user->Compute(command);
	command = new CalculatorCommand(calculator, '-', 50);
	user->Compute(command);
	command = new CalculatorCommand(calculator, '*', 10);
	user->Compute(command);
	command = new CalculatorCommand(calculator, '/', 2);
	user->Compute(command);

	// Undo 4 commands
	user->Undo(4);
	// Redo 2 commands
	user->Redo(2);

	return 0;
}


