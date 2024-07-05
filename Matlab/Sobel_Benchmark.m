function edge = Sobel_Benchmark(img)
	% load the inputs
	dim = size(img);
	gain = 1/8;

	% initalize the x and y gradients
	Gx = zeros(dim);
	Gy = zeros(dim);

	for i = 2:dim(1)-1
		for j = 2:dim(2)-1
			% convolute using the sobel operator
			Gx(i, j) = gain*(img(i-1,j-1) + 2*img(i,j-1) + img(i+1,j-1) -...
				(img(i-1,j+1) + 2*img(i,j+1) + img(i+1,j+1)));

			Gy(i, j) = gain*(img(i-1,j-1) + 2*img(i-1,j) + img(i-1,j+1) -...
				(img(i+1,j-1) + 2*img(i+1,j) + img(i+1,j+1)));
		end
	end

	edge = sqrt(Gx.^2 + Gy.^2);
end