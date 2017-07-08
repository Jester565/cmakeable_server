#include "dataframe.h"
#include <vector>
#include <boost/shared_ptr.hpp>

namespace websocket
{
	class dataframe_parser;

	class dataframe_manager
	{
	public:
		const static unsigned int USE_VEC_SIZE = 0;

		dataframe_manager();

		boost::shared_ptr<websocket::dataframe> parse_data(const std::vector <unsigned char>& data, unsigned int size);

		boost::shared_ptr<websocket::dataframe> parse_data(unsigned char* data, unsigned int size);

		~dataframe_manager();

	protected:
		dataframe_parser* df_parser;
	};
}
