#pragma once
#include "EasyCNN/Configure.h"
#include "EasyCNN/Layer.h"

namespace EasyCNN
{
	class ConvolutionLayer : public Layer
	{
	public:
		ConvolutionLayer();
		virtual ~ConvolutionLayer();
	public:
		void setParamaters(const BucketSize _kernelSize, const int _step,const bool _enabledBias);
	public:
		DECLARE_LAYER_TYPE;
		virtual std::string getLayerType() const;
		virtual void solveInnerParams();
		virtual void forward(const std::shared_ptr<DataBucket> prevDataBucket, std::shared_ptr<DataBucket> nextDataBucket);
		virtual void backward(std::shared_ptr<DataBucket> prevDataBucket, const std::shared_ptr<DataBucket> nextDataBucket);
	private:
		BucketSize kernelSize;
		int step = 0;
		std::shared_ptr<DataBucket> kernelData;
		bool enabledBias = false;
		std::shared_ptr<DataBucket> biasData;
	};
}