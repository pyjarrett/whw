#include <iostream>
#include <string>
#include <string_view>

bool includesNullTerminator(std::string_view view)
{
	return !view.empty() && view.at(view.length() - 1) == '\0';
}

bool hasNullTerminator(std::string_view view)
{
	return *(view.data() + view.length()) == '\0';
}

void printProperties(const char* testName, std::string_view view)
{
	std::cout << "===========" << testName << "===========\n";
	std::cout << "Contents: \"" << view << "\"\n";
	std::cout << "           ";
	for (size_t i = 0; i < view.length(); ++i) {
		std::cout << (i % 10);
	}
	std::cout << '\n';
	if (!view.empty()) {
		std::cout << "Last 'valid' byte:" << view[view.length() - 1] << '(' << std::dec << int(view[view.length() - 1]) << ")\n";
	}
	std::cout << "Byte after last 'valid' byte:" << std::dec << int(view.data()[view.length()]) << '\n';
	std::cout << "Two bytes after last 'valid' byte:" << std::dec << int(view.data()[view.length() + 1]) << '\n';
	std::cout << "Length: " << view.length() << '\n';
	std::cout << "Is empty? " << view.empty() << '\n';
	std::cout << "Contents includes null terminator? " << includesNullTerminator(view) << '\n';
	std::cout << "Has null terminator? " << hasNullTerminator(view) << '\n';
	std::cout << '\n';
}

int main()
{
	{
		char array[7] = {'l', 'i', 't', 'e', 'r', 'a', 'l'};
		std::string_view fromArray(array, 7);
		printProperties("From char array without a null terminator", fromArray);

		const char* literal = "literal";
		std::string_view fromLiteral(literal, 7);

		std::cout << "Compares the same without null terminator afterwards? " << (fromArray == fromLiteral) << '\n';
	}

	{
		const char* literal = "this is a literal";
		std::string_view view = literal;
		printProperties("From const char* variable", view);
	}

	{
		std::string_view view = "this is a literal";
		printProperties("From const char* literal", view);
	}

	{
		const char* emptyLiteral = "";
		std::string_view view = emptyLiteral;
		printProperties("From empty literal variable", view);
	}

	{
		const char* literal = "this is a literal";
		std::string_view view(literal + 5, 2);
		printProperties("Slice of const char* literal", view);
	}

	{
		std::string str = "this is a literal";
		std::string_view view = str;
		printProperties("From string", view);
	}

	// WOW! string_views print properly, both with and without null terminators.
	{
		std::string str = "this is a literal";
		std::string_view slice(str.data() + 5, 2);
		printProperties("Slice from string", slice);
		printProperties("Converted from full string", (std::string_view)str);
		printProperties("Converted from full string with null terminator", std::string_view(str.data(), str.length() + 1));
	}

	return 0;
}