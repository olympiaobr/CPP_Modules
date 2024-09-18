#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Test 1: Create bureaucrats and forms with different grades
        Bureaucrat kiki("Kiki", 1); // Highest grade
        Bureaucrat miki("Miki", 50);    // Middle grade
        Bureaucrat vikki("Vikki", 150); // Lowest grade

        Form formA("FormA", 10, 20);   // Requires grade 10 to sign
        Form formB("FormB", 50, 100);  // Requires grade 50 to sign
        Form formC("FormC", 1, 1);     // Requires grade 1 to sign

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

        // Test 2: Signing forms with different bureaucrats
        std::cout << "\nAttempting to sign forms with different bureaucrats:\n";
        kiki.signForm(formA); // Should succeed
        miki.signForm(formB);   // Should succeed
        vikki.signForm(formC); // Should fail due to low grade

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

        // Test 3: Try signing already signed forms
        std::cout << "\nAttempting to re-sign forms:\n";
        kiki.signForm(formA); // Already signed, should still be okay
        miki.signForm(formB);   // Already signed, should still be okay

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        // Test 4: Create a form with invalid grades and handle exceptions
        std::cout << "\nAttempting to create forms with invalid grades:\n";
        try {
            Form invalidForm("InvalidForm", 0, 10); // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            Form invalidForm("InvalidForm", 10, 151); // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

