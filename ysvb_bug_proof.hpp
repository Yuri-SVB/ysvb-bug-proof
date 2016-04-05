/*
 * ysvb_bug_proof.hpp
 *
 *  Created on: Dec 14, 2014
 *      Author: yuri
 */

#if !defined(YSVB_BUG_PROOF_HPP_)
#define YSVB_BUG_PROOF_HPP_

 		//General purpose math tool
#define SIGN(x) ((x < 0) ? (-1) : (x > 0))

		//MENU
 	//Comment / Uncomment each of those lines bellow to selectively activate each functionallity
// #define __SHOW__
// #define __LOG__
// #define __PUT__
// #define __DBG__       
// #define __TODO__


 		//TODO
 	//Rudimentar way to register ideas within the code that can be recalled by simply compiling the code with __TODO__ macro defined
#if defined(__TODO__)
	#define TODO(X)	ç
#else
	#define TODO(X)
#endif

#include <iostream>

		//YSVB_CHECK
 	//Here starts the big thing:
 	//YSVB_CHECK_1 takes two operands A and B, an (binary, boolean returning) operator O, and a text H
 	//O to return true as result of operating A and B is something the tester expects the program to 
 	//happen for whatever reason. This is specially useful as a confirmation that the program flow is
 	//well conceived and implemented. If it does not happen, then !(A O B) equals true, and hence
 	//the macro outputs a warning message at the log file, also giving a Hint H (by the tester)
 	//of what most likely the problem is.
#if defined (__DBG__)
	#define YSVB_CHECK_1(A, O, B, H) if ( !(A O B) )\
	{\
		std::cout << "error at " << __FILE__ << "	line	" << __LINE__ << std::endl <<\
		#A << " = " << (A) << std::endl <<\
		#B << " = " << (B) << std::endl <<\
		"( " << #A << " " << #O << " " << #B << " ) = " << "FALSE" << std::endl <<\
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_1(A, O, B, H)
#endif

		//YSVB_CHECK_N
	//YSVB_CHECK_N is the same as YSVB_CHECK_1 but making N boolean returning binary operations
	//and checking wheter any of them are true. Checking whether all of a set of N is true is simple:
	//It only takes making N YSVB_CHECK_1 tests. Those specially are useful to make conditional tests, as
	//A -> B is equivalent to (!A || B). All YSVB_CHECK_N tests are implemented until N = 10, though it 
	//is very simple to extend it
#if defined (__DBG__)
	#define YSVB_CHECK_2(A1, O1, B1, A2, O2, B2, H) if ( !(	(A1 O1 B1) || (A2 O2 B2)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl <<\
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_2(A1, O1, B1, A2, O2, B2, H)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_3(A1, O1, B1, A2, O2, B2, A3, O3, B3, H) if ( !(	(A1 O1 B1) || (A2 O2 B2) || (A3 O3 B3)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl << \
		#A3 << " = " << (A3) << std::endl <<\
		#B3 << " = " << (B3) << std::endl <<\
		"( " << #A3 << " " << #O3 << " " << #B3 << " ) = " << (A3 O3 B3) << std::endl << \
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_3(A1, O1, B1, A2, O2, B2, A3, O3, B3)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_4(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, H) if ( !(	(A1 O1 B1) || (A2 O2 B2) || (A3 O3 B3) || (A4 O4 B4)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl << \
		#A3 << " = " << (A3) << std::endl <<\
		#B3 << " = " << (B3) << std::endl <<\
		"( " << #A3 << " " << #O3 << " " << #B3 << " ) = " << (A3 O3 B3) << std::endl << \
		#A4 << " = " << (A4) << std::endl <<\
		#B4 << " = " << (B4) << std::endl <<\
		"( " << #A4 << " " << #O4 << " " << #B4 << " ) = " << (A4 O4 B4) << std::endl << \
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_4(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, H)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_5(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, H) if ( !(	(A1 O1 B1) || (A2 O2 B2) || (A3 O3 B3) || (A4 O4 B4) || (A5 O5 B5)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl << \
		#A3 << " = " << (A3) << std::endl <<\
		#B3 << " = " << (B3) << std::endl <<\
		"( " << #A3 << " " << #O3 << " " << #B3 << " ) = " << (A3 O3 B3) << std::endl << \
		#A4 << " = " << (A4) << std::endl <<\
		#B4 << " = " << (B4) << std::endl <<\
		"( " << #A4 << " " << #O4 << " " << #B4 << " ) = " << (A4 O4 B4) << std::endl << \
		#A5 << " = " << (A5) << std::endl <<\
		#B5 << " = " << (B5) << std::endl <<\
		"( " << #A5 << " " << #O5 << " " << #B5 << " ) = " << (A5 O5 B5) << std::endl << \
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_5(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, H)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_6(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, A6, O6, B6, H) if ( !(	(A1 O1 B1) || (A2 O2 B2) || (A3 O3 B3) || (A4 O4 B4) || (A5 O5 B5) || (A6 O6 B6)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl << \
		#A3 << " = " << (A3) << std::endl <<\
		#B3 << " = " << (B3) << std::endl <<\
		"( " << #A3 << " " << #O3 << " " << #B3 << " ) = " << (A3 O3 B3) << std::endl << \
		#A4 << " = " << (A4) << std::endl <<\
		#B4 << " = " << (B4) << std::endl <<\
		"( " << #A4 << " " << #O4 << " " << #B4 << " ) = " << (A4 O4 B4) << std::endl << \
		#A5 << " = " << (A5) << std::endl <<\
		#B5 << " = " << (B5) << std::endl <<\
		"( " << #A5 << " " << #O5 << " " << #B5 << " ) = " << (A5 O5 B5) << std::endl << \
		#A6 << " = " << (A6) << std::endl <<\
		#B6 << " = " << (B6) << std::endl <<\
		"( " << #A6 << " " << #O6 << " " << #B6 << " ) = " << (A6 O6 B6) << std::endl << \
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_6(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, A6, O6, B6, H)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_7(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, A6, O6, B6, A7, O7, B7, H) if ( !(	(A1 O1 B1) || (A2 O2 B2) || (A3 O3 B3) || (A4 O4 B4) || (A5 O5 B5) || (A6 O6 B6) || (A7 O7 B7)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl << \
		#A3 << " = " << (A3) << std::endl <<\
		#B3 << " = " << (B3) << std::endl <<\
		"( " << #A3 << " " << #O3 << " " << #B3 << " ) = " << (A3 O3 B3) << std::endl << \
		#A4 << " = " << (A4) << std::endl <<\
		#B4 << " = " << (B4) << std::endl <<\
		"( " << #A4 << " " << #O4 << " " << #B4 << " ) = " << (A4 O4 B4) << std::endl << \
		#A5 << " = " << (A5) << std::endl <<\
		#B5 << " = " << (B5) << std::endl <<\
		"( " << #A5 << " " << #O5 << " " << #B5 << " ) = " << (A5 O5 B5) << std::endl << \
		#A6 << " = " << (A6) << std::endl <<\
		#B6 << " = " << (B6) << std::endl <<\
		"( " << #A6 << " " << #O6 << " " << #B6 << " ) = " << (A6 O6 B6) << std::endl << \
		#A7 << " = " << (A7) << std::endl <<\
		#B7 << " = " << (B7) << std::endl <<\
		"( " << #A7 << " " << #O7 << " " << #B7 << " ) = " << (A7 O7 B7) << std::endl << \
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_7(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, A6, O6, B6, A7, O7, B7, H)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_8(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, A6, O6, B6, A7, O7, B7, A8, O8, B8, H) if ( !(	(A1 O1 B1) || (A2 O2 B2) || (A3 O3 B3) || (A4 O4 B4) || (A5 O5 B5) || (A6 O6 B6) || (A7 O7 B7) || (A8 O8 B8)	) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		#A1 << " = " << (A1) << std::endl <<\
		#B1 << " = " << (B1) << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << (A2) << std::endl <<\
		#B2 << " = " << (B2) << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl << \
		#A3 << " = " << (A3) << std::endl <<\
		#B3 << " = " << (B3) << std::endl <<\
		"( " << #A3 << " " << #O3 << " " << #B3 << " ) = " << (A3 O3 B3) << std::endl << \
		#A4 << " = " << (A4) << std::endl <<\
		#B4 << " = " << (B4) << std::endl <<\
		"( " << #A4 << " " << #O4 << " " << #B4 << " ) = " << (A4 O4 B4) << std::endl << \
		#A5 << " = " << (A5) << std::endl <<\
		#B5 << " = " << (B5) << std::endl <<\
		"( " << #A5 << " " << #O5 << " " << #B5 << " ) = " << (A5 O5 B5) << std::endl << \
		#A6 << " = " << (A6) << std::endl <<\
		#B6 << " = " << (B6) << std::endl <<\
		"( " << #A6 << " " << #O6 << " " << #B6 << " ) = " << (A6 O6 B6) << std::endl << \
		#A7 << " = " << (A7) << std::endl <<\
		#B7 << " = " << (B7) << std::endl <<\
		"( " << #A7 << " " << #O7 << " " << #B7 << " ) = " << (A7 O7 B7) << std::endl << \
		#A8 << " = " << (A8) << std::endl <<\
		#B8 << " = " << (B8) << std::endl <<\
		"( " << #A8 << " " << #O8 << " " << #B8 << " ) = " << (A8 O8 B8) << std::endl << \
		"Hint: " << H << std::endl;\
	}
#else
	#define YSVB_CHECK_8(A1, O1, B1, A2, O2, B2, A3, O3, B3, A4, O4, B4, A5, O5, B5, A6, O6, B6, A7, O7, B7, A8, O8, B8, H)
#endif


			//YSVB_CHECK_Ps
		//The same but for pointers or iterators
#if defined (__DBG__)
	#define YSVB_CHECK_1P(A, O, B) if ( !(A O B) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		"*" << #A << " = " << (*(A)) << std::endl <<\
		"*" << #B << " = " << (*(B)) << std::endl <<\
		"( " << #A << " " << #O << " " << #B << " ) = " << "FALSE" << std::endl;\
	}
#else
	#define YSVB_CHECK_1P(A, O, B)
#endif

#if defined (__DBG__)
	#define YSVB_CHECK_2P(A1, O1, B1, A2, O2, B2) if ( !(A1 O1 B1 || A2 O2 B2) )\
	{\
		std::cout << "error at " << __FILE__ << "\t\t" << __LINE__ << std::endl <<\
		"*" << #A1 << " = " << *A1 << std::endl <<\
		"*" << #B1 << " = " << *B1 << std::endl <<\
		"( " << #A1 << " " << #O1 << " " << #B1 << " ) = " << (A1 O1 B1) << std::endl << \
		#A2 << " = " << A2 << std::endl <<\
		#B2 << " = " << B2 << std::endl <<\
		"( " << #A2 << " " << #O2 << " " << #B2 << " ) = " << (A2 O2 B2) << std::endl;\
	}
#else
	#define YSVB_CHECK_2P(A, O, B)
#endif

			//Some simple log tools

		//SHOW
#if defined (__SHOW__)
	#define YSVB_SHOW(X) (std::cout<<__FILE__<<"\t"<<__LINE__<<"\t"<<#X<<"="<<(X)<<std::endl);
#else
	#define YSVB_SHOW(X)
#endif

		//LOG
#if defined (__LOG__)
	#define YSVB_LOG(TEXT) (std::cout<<__FILE__<<"\t"<<__LINE__<<"\t"<<#TEXT<<std::endl);
#else
	#define YSVB_LOG(TEXT)
#endif

		//LOG
#if defined (__PUT__)
	#define YSVB_PUT(X) (std::cout<<__FILE__<<"\t"<<__LINE__<<"\t"<<std::string(X)<<std::endl);
#else
	#define YSVB_PUT(X)
#endif

#endif /* YSVB_BUG_PROOF_HPP_ */