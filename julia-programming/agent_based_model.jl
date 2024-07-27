# agent_based_model.jl

using Random
using Plots
using Statistics

# --- Parameters and Initialization ---

const GRID_SIZE = 50       # Size of the grid
const NUM_AGENTS = 100     # Number of agents
const NUM_STEPS = 1000     # Number of simulation steps
const PLOT_INTERVAL = 100  # Interval for plotting (every 100 steps)

# Initialize random number generator
rng = MersenneTwister(1234)

# Agent structure
mutable struct Agent
    x::Int
    y::Int
end

# Initialize agents randomly on the grid
function initialize_agents(num_agents::Int, grid_size::Int)
    agents = [Agent(rand(1:grid_size), rand(1:grid_size)) for _ in 1:num_agents]
    return agents
end

# --- Movement and Interaction Logic ---

# Move agents randomly
function move_agents!(agents::Vector{Agent}, grid_size::Int, rng::AbstractRNG)
    for agent in agents
        dx = rand(rng, [-1, 0, 1])
        dy = rand(rng, [-1, 0, 1])
        agent.x = clamp(agent.x + dx, 1, grid_size)
        agent.y = clamp(agent.y + dy, 1, grid_size)
    end
end

# Interaction logic (e.g., check for collisions)
function interact_agents!(agents::Vector{Agent})
    for i in 1:length(agents)
        for j in i+1:length(agents)
            if agents[i].x == agents[j].x && agents[i].y == agents[j].y
                # Example interaction: swap positions
                agents[i], agents[j] = agents[j], agents[i]
            end
        end
    end
end

# --- Data Collection and Analysis ---

# Collect data: positions of all agents
function collect_data(agents::Vector{Agent})
    x_positions = [agent.x for agent in agents]
    y_positions = [agent.y for agent in agents]
    return x_positions, y_positions
end

# Compute statistics (e.g., mean position)
function compute_statistics(x_positions::Vector{Int}, y_positions::Vector{Int})
    mean_x = mean(x_positions)
    mean_y = mean(y_positions)
    return mean_x, mean_y
end

# --- Visualization ---

# Plot agents on the grid
function plot_agents(x_positions::Vector{Int}, y_positions::Vector{Int}, step::Int)
    p = scatter(x_positions, y_positions, title="Agent Positions at Step $step",
                xlabel="X Position", ylabel="Y Position", legend=false, marker=:circle)
    savefig("plot_step_$step.png")
end

# --- Main Simulation Loop ---

function run_simulation()
    agents = initialize_agents(NUM_AGENTS, GRID_SIZE)
    for step in 1:NUM_STEPS
        move_agents!(agents, GRID_SIZE, rng)
        interact_agents!(agents)
        if step % PLOT_INTERVAL == 0
            x_positions, y_positions = collect_data(agents)
            plot_agents(x_positions, y_positions, step)
        end
    end
end

# Execute the simulation
run_simulation()
