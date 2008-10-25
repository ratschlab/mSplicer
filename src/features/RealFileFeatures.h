/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2008 Soeren Sonnenburg
 * Copyright (C) 1999-2008 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _DREALFILEFEATURES__H__
#define _DREALFILEFEATURES__H__

#include "lib/common.h"
#include "features/RealFeatures.h"

/** The class RealFileFeatures implements a dense double-precision floating
 * point matrix <b>from a file</b>.  It inherits its functionality from
 * CSimpleFeatures, which should be consulted for further reference.
 */
class CRealFileFeatures: public CRealFeatures
{
	public:
		/** constructor
		 *
		 * @param size cache size
		 * @param file file to load features from
		 */
		CRealFileFeatures(INT size, FILE* file);

		/** constructor
		 *
		 * @param size cache size
		 * @param filename filename to load features from
		 */
		CRealFileFeatures(INT size, char* filename);

		/** copy constructor */
		CRealFileFeatures(const CRealFileFeatures& orig);

		virtual ~CRealFileFeatures();

		/** load feature matrix
		 *
		 * @return loaded feature matrix
		 */
		virtual DREAL* load_feature_matrix();

		/** get label at given index
		 *
		 * @param idx index to look at
		 * @return label at given index
		 */
		INT get_label(INT idx);

	protected:
		/** compute feature vector for sample num
		 * len is returned by reference
		 *
		 * @param num num
		 * @param len len
		 * @param target target
		 */
		virtual DREAL* compute_feature_vector(INT num, INT& len, DREAL* target=NULL);

		/** load base data
		 *
		 * @return if loading was successful
		 */
		bool load_base_data();

		/** working file */
		FILE* working_file;
		/** working filename */
		char* working_filename;
		/** status */
		bool status;
		/** labels */
		INT* labels;

		/** intlen */
		uint8_t intlen;
		/** doublelen */
		uint8_t doublelen;
		/** endian */
		uint32_t endian;
		/** fourcc */
		uint32_t fourcc;
		/** preprocd */
		uint32_t preprocd;
		/** filepos */
		LONG filepos;
};
#endif
