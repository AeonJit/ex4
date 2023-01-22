//
// Created by Amit and Tal on 18/01/2023.
//
#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#define DEBUG
 #include <exception>
 #include <iostream>

 class DeckFileNotFound : public std::exception
 {
    public:
   const char* what() const noexcept override
   {   
       #ifdef DEBUG
       std::cout << EXCEPTION_MSG << std::endl;
       #endif
       return EXCEPTION_MSG;
   }
   
   private:
   static constexpr const char*  EXCEPTION_MSG = "Deck File Error: File not found";

 };

 class DeckFileFormatError : public std::exception
 {
    public:
    DeckFileFormatError(int line)  
    {
        m_exceptionMsg += std::to_string(line);
    }
    
   const char* what() const noexcept override
   {    
       #ifdef DEBUG
       std::cout << m_exceptionMsg << std::endl;
       #endif
       return m_exceptionMsg.c_str();
   }
   
   private:
   std::string  m_exceptionMsg = "Deck File Error: File format error in line ";
 };

class DeckFileInvalidSize : public std::exception
{
    public:
      const char* what() const noexcept override
   {    
       #ifdef DEBUG
       std::cout << SIZE_INVALID_MSG << std::endl;
       #endif
       return SIZE_INVALID_MSG;
   }

   private:
   static constexpr const char* SIZE_INVALID_MSG = "Deck File Error: Deck size is invalid";

};

#endif //EXCEPTION_H_ 