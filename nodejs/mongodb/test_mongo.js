const mongoose = require('mongoose');

async function run() {
    try {
        await mongoose.connect('mongodb://localhost:27017/testdb');
        console.log('✅ Connected to MongoDB!');
        await mongoose.connection.close();
    } catch (err) {
        console.error('❌ Connection error:', err);
    }
}

run();
