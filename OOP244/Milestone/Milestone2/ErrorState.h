/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/18/2018
**********************************************************/
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace AMA {
	class ErrorState {
		char *m_message;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator =(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& ostr, ErrorState& obj);

}
#endif // !SICT_ERRORSTATE_H
