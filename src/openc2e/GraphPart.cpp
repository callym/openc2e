#include "GraphPart.h"

GraphPart::GraphPart(Agent* p, unsigned int _id, std::string spritefile, unsigned int fimg, int _x, int _y,
	unsigned int _z, unsigned int novalues)
	: SpritePart(p, _id, spritefile, fimg, _x, _y, _z) {
	// TODO: store novalues
	(void)novalues;
}