const ProductReviews = async ({
    params,
}: {
    params: Promise<{ productId: string }>;
}) => {

    const productId = (await params).productId;
    
    return (

        <div>
            <h1>All reviews for product {productId}</h1>
            <ul>
                <li>Review 1</li>
                <li>Review 2</li>
                <li>Review 3</li>
                <li>Review 4</li>
            </ul>
        </div>

    );
};

export default ProductReviews;