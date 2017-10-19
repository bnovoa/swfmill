#include <SWFFilter.h>
#include "gSWF.h"

namespace SWF {

	Filter *Filter::get(Reader *r, int end, Context *ctx) {
		int type = r->getByte();
		int len = end - r->getPosition();

		Filter* ret = getByType(type);

		if (!ret) {
			ret = new UnknownFilter();
		}

		ret->setType(type);
		ret->setLength(len);
		ret->parse(r, end, ctx);

		return ret;
	}

}
