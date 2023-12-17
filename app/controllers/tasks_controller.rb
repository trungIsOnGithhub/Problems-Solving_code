class TasksController < ApplicationController
    before_action :authenticate_user!
    before_action :set_plan
    before_action :set_task, only: [:show, :edit, :update, :destroy]
  
    # GET plans/1/tasks
    def index
      @tasks = @plan.tasks
    end 
  
    # GET plans/1/tasks/1
    def show
    end
  
    # GET plans/1/tasks/new
    def new
      @task = @plan.tasks.build
    end
  
    # GET plans/1/tasks/1/edit
    def edit
    end
  
    # POST plans/1/tasks
    def create
        @task = @plan.tasks.build(task_params)

        if @task.save
            redirect_to(@task.plan)
        else
            render action: 'new'
        end
    end
  
    # PUT plans/1/tasks/1
    def update
        if @task.update_attributes(task_params)
        redirect_to(@task.plan)
        else
        render action: 'edit'
        end
    end
  
    # DELETE plans/1/tasks/1
    def destroy
        @task.destroy

        redirect_to @plan
    end
  
    private
        # Use callbacks to share common setup or constraints between actions.
        def set_plan
            @plan = current_user.plans.find(params[:plan_id])
        end

        def set_task
            @task = @plan.tasks.find(params[:id])
        end
  
    # Only allow a trusted parameter "white list" through.
    def task_params
        params.require(:task).permit(:name, :description, :status, :plan_id)
    end
end 